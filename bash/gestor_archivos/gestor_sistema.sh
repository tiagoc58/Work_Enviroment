#!/bin/bash
si=0
actual_dir=""

crear_archivos() {
    si=1 
    read -rp "Ingrese la ruta del directorio: " dir 
    read -rp "Ingrese la cantidad de archivos: " archs 
    read -rp "Ingrese la cantidad de lineas por archivo: " lines 
    
    #validar el numero ingresado
    if [[ ! "$archs" =~ ^[1-9][0-9]*$ || ! "$lines" =~ ^[1-9][0-9]*$ ]]; then
        echo "Error, el o los numeros ingresados no son validos."
        echo "Intente de nuevo."
        return
    fi

    #validar que no sea una ruta a un archivo existente
    if [ -f "$dir" ]; then 
        echo "Error, la ruta ingresada no es válida."
        echo "Intente de nuevo."
        return
    fi

    #si el directorio no existe se crea o si es existente, que tenga permisos de escritura
    funciona=0
    if [ ! -d "$dir" ]; then 
        mkdir -vp "$dir" 2> /dev/null
        funciona=$?
    elif [ ! -w "$dir" ]; then
        echo "Error, la ruta ingresada no tiene permisos de escritura."
        echo "Intente de nuevo."
        return
    fi  

    #validar que si se haya podido crear el directorio 
    if [ $funciona -ne 0 ]; then
        echo "Error, usted no tiene permisos para crear el o los directorios."
        echo "Intente de nuevo."
        return
    fi

    local i=1
    while [ $i -le "$archs" ]; do
        #eliminacion del archivo si ya existe
        if [ -f "$dir/archivo-${i}.txt" ]; then
            rm "$dir/archivo-${i}.txt"
        fi

        #creacion del archivo
        touch "$dir/archivo-${i}.txt" 
        
        #anexacion de las lineas de manera aleatoria
        local j=1
        while [ $j -le "$lines" ]; do
            num=$((RANDOM % 100 + 1))
            men=$(head -$num "$(pwd)/chistes_100.txt" | tail -1)
            echo "$men" >> "$dir/archivo-${i}.txt"
            j=$((j+1))
        done

        #cambio de permisos del archivo
        local X=$((RANDOM % 8))
        local Y=$((RANDOM % 8))
        chmod 6$X$Y "$dir/archivo-${i}.txt" 

        i=$((i+1))
    done
    actual_dir=$dir
}

listar_archivos() {
    local dir=$actual_dir
    if [ $# -eq 1 ]; then
        dir="$1"
    fi
    
    if [ ! -d "$dir" ]; then
        echo "Error, la ruta ingresada no es válida."
        echo "Intente de nuevo."
        return
    fi

    local tmp=""
    for file in $(ls "$dir"); do
        if [ -f "$dir/$file" ]; then
            propietario=$(stat -c "%U" "$dir/$file")
            tamano=$(stat -c "%s" "$dir/$file")
            permisos=$(stat -c "%A" "$dir/$file")
            tmp="${tmp}Nombre: $file | Propietario: $propietario | Tamaño: $tamano bytes | Permisos: $permisos\n"
        fi
    done
    echo -e "$tmp" | sort -V
}

buscar_texto() {
    local palabra_clave=$1
    local cantidad_archivos=0
    for file in $(ls "$actual_dir"); do
        if [ -f "$actual_dir/$file" ]; then
            lista=$(grep -n "$palabra_clave" "$actual_dir/$file")
            if [ -z "$lista" ]; then
                continue
            fi
            echo "--------------------------------------------------------------------"
            echo "El archivo $file tiene las siguientes coincidencias en las lineas..."
            echo "$lista"
            echo "--------------------------------------------------------------------"
            cantidad_archivos=$((cantidad_archivos+1))
        fi
    done
    echo "Cantidad de archivos que coincidieron con el patron: $cantidad_archivos"
}

procesar_archivos() {
    local dir=$actual_dir
    if [ $# -eq 1 ]; then
        dir="$1"
    fi
    
    if [ ! -d "$dir" ]; then
        echo "Error, la ruta ingresada no es válida."
        echo "Intente de nuevo."
        return
    fi

    for file in "$dir"/*.txt; do
        if [ -f "$file" ]; then
            total_lineas=$(wc -l < "$file")
            sort "$file" | uniq > "${file}.tmp"
            lineas_unicas=$(wc -l < "${file}.tmp")
            mv "${file}.tmp" "$file"
            echo "Archivo: $(basename "$file")"
            echo "  Líneas totales: $total_lineas"
            echo "  Líneas únicas : $lineas_unicas"
        fi
    done
}

estadistica() {
    local dir=$actual_dir
    if [ $# -eq 1 ]; then
        dir="$1"
    fi
    
    if [ ! -d "$dir" ]; then
        echo "Error, la ruta ingresada no es válida."
        echo "Intente de nuevo."
        return
    fi

    echo "+----------------+---------+---------+---------+"
    echo "|     Archivo    |    U    |    G    |    O    |"
    echo "|                |  r w x  |  r w x  |  r w x  |"
    echo "+----------------+---------+---------+---------+"

    total_r_u=0; total_w_u=0; total_x_u=0
    total_r_g=0; total_w_g=0; total_x_g=0
    total_r_o=0; total_w_o=0; total_x_o=0

    for file in $(ls "$dir" | sort -V); do
        if [ -f "$dir/$file" ]; then
            permisos=$(ls -l "$dir/$file" | cut -d' ' -f1)

            # Usuario
            ur=$(echo "$permisos" | cut -c2)
            uw=$(echo "$permisos" | cut -c3)
            ux=$(echo "$permisos" | cut -c4)
            # Grupo
            gr=$(echo "$permisos" | cut -c5)
            gw=$(echo "$permisos" | cut -c6)
            gx=$(echo "$permisos" | cut -c7)
            # Otros
            or=$(echo "$permisos" | cut -c8)
            ow=$(echo "$permisos" | cut -c9)
            ox=$(echo "$permisos" | cut -c10)

            echo "|   $(echo "$file" | cut -c1-10)   |  $ur $uw $ux  |  $gr $gw $gx  |  $or $ow $ox  |"

            # Contadores U
            if [ "$ur" = "r" ]; then
                total_r_u=$((total_r_u+1))
            fi
            if [ "$uw" = "w" ]; then
                total_w_u=$((total_w_u+1))
            fi
            if [ "$ux" = "x" ]; then
                total_x_u=$((total_x_u+1))
            fi

            # Contadores G
            if [ "$gr" = "r" ]; then
                total_r_g=$((total_r_g+1))
            fi
            if [ "$gw" = "w" ]; then
                total_w_g=$((total_w_g+1))
            fi
            if [ "$gx" = "x" ]; then
                total_x_g=$((total_x_g+1))
            fi

            # Contadores O
            if [ "$or" = "r" ]; then
                total_r_o=$((total_r_o+1))
            fi
            if [ "$ow" = "w" ]; then
                total_w_o=$((total_w_o+1))
            fi
            if [ "$ox" = "x" ]; then
                total_x_o=$((total_x_o+1))
            fi
        fi
    done

    echo "+----------------+---------+---------+---------+"
    echo "|   TOTAL 'r' ⇒  |    $total_r_u    |    $total_r_g    |    $total_r_o    |"
    echo "|   TOTAL 'w' ⇒  |    $total_w_u    |    $total_w_g    |    $total_w_o    |"
    echo "|   TOTAL 'x' ⇒  |    $total_x_u    |    $total_x_g    |    $total_x_o    |"
    echo "+----------------+---------+---------+---------+"
}

ayuda() {
    echo "+------------------------------------------------------------+"
    echo "|                            AYUDA                           |"
    echo "+------------------------------------------------------------+"
    echo "| Descripción general:                                       |"
    echo "|  Este script permite gestionar archivos de texto dentro    |"
    echo "|  de un directorio. Ofrece opciones para crear, listar,     |"
    echo "|  buscar texto, eliminar duplicados y ver estadísticas      |"
    echo "|  detalladas de permisos.                                   |"
    echo "+------------------------------------------------------------+"
    echo "| OPCIONES DISPONIBLES:                                      |"
    echo "+------------------------------------------------------------+"
    echo "| 0) CREAR ARCHIVOS                                          |"
    echo "|    Crea un número de archivos de texto con contenido       |"
    echo "|    aleatorio, dentro de un directorio indicado por el      |"
    echo "|    usuario. Si el directorio no existe, se crea.           |"
    echo "+------------------------------------------------------------+"
    echo "| 1) LISTAR ARCHIVOS                                         |"
    echo "|    Muestra los archivos del directorio con su nombre,      |"
    echo "|    propietario, tamaño y permisos. Se ordenan por nombre.  |"
    echo "+------------------------------------------------------------+"
    echo "| 2) BUSCAR TEXTO                                            |"
    echo "|    Busca una palabra o patrón dentro de los archivos del   |"
    echo "|    ultimo directorio creado, mostrando las líneas          |"
    echo "|    coincidentes y la cantidad de archivos con coincidencias|"
    echo "+------------------------------------------------------------+"
    echo "| 3) PROCESAR ARCHIVOS                                       |"
    echo "|    Elimina las líneas duplicadas de cada archivo, mostrando|"
    echo "|    el total de líneas originales y únicas por archivo.     |"
    echo "+------------------------------------------------------------+"
    echo "| 4) ESTADÍSTICA                                             |"
    echo "|    Muestra una tabla con los permisos de cada archivo      |"
    echo "|    (r, w, x) para Usuario, Grupo y Otros, y al final un    |"
    echo "|    resumen total.                                          |"
    echo "+------------------------------------------------------------+"
    echo "| 5) AYUDA                                                   |"
    echo "|    Muestra esta información descriptiva.                   |"
    echo "+------------------------------------------------------------+"
    echo "| 6) SALIR                                                   |"
    echo "|    Termina la ejecución del programa.                      |"
    echo "+------------------------------------------------------------+"
    echo "| Uso general:                                               |"
    echo "|    ./fileman.sh                                            |"
    echo "|    Luego seleccione una opción del menú.                   |"
    echo "+------------------------------------------------------------+"
}

clear
echo "===== FILEMAN - Gestor avanzado de archivos ====="
echo "0) Crear archivos"
echo "1) Listar archivos"
echo "2) Buscar texto"
echo "3) Procesar archivos"
echo "4) Estadistica"
echo "5) Ayuda"
echo "6) Salir"

while true; do
    echo "==============================================="
    read -rp "Seleccione una opción: " opcion
    case $opcion in
        0)
            echo "-------- CREAR ARCHIVOS --------"
            crear_archivos
            ;;
        1)  
            if [ $si -eq 0 ]; then
                echo -e "Error, antes de usar esta opcion primero debe usar la opcion 0.\nIntente de nuevo."
                continue
            fi
            echo "-------- LISTAR ARCHIVOS --------"
            read -rp "Ingrese la ruta del directorio a listar: " dir
            if [ -n "$dir" ]; then
                listar_archivos "$dir"
            else
                listar_archivos
            fi
            ;;
        2)
            if [ $si -eq 0 ]; then
                echo -e "Error, antes de usar esta opcion primero debe usar la opcion 0.\nIntente de nuevo."
                continue
            fi
            echo "-------- BUSCAR TEXTO --------"
            read -rp "Ingrese la palabra clave a buscar: " palabra_clave
            buscar_texto "$palabra_clave"
            ;;
        3)
            if [ $si -eq 0 ]; then
                echo -e "Error, antes de usar esta opcion primero debe usar la opcion 0.\nIntente de nuevo."
                continue
            fi
            echo "-------- PROCESAR ARCHIVOS --------"
            read -rp "Ingrese la ruta del directorio el cual quiere procesar: " dir
            if [ -n "$dir" ]; then
                procesar_archivos "$dir"
            else
                procesar_archivos
            fi
            ;;
        4)
            if [ $si -eq 0 ]; then
                echo -e "Error, antes de usar esta opcion primero debe usar la opcion 0.\nIntente de nuevo."
                continue
            fi
            echo "-------- ESTADÍSTICA --------"
            read -rp "Ingrese la ruta del directorio el cual quiere procesar: " dir
            if [ -n "$dir" ]; then
                estadistica "$dir"
            else
                estadistica
            fi
            ;;
        5)
            ayuda
            ;;
        6)
            echo "Saliendo de Fileman..."
            read -rp "¿Limpiar la consola? (s/n) " opcion
            if [ "$opcion" = "s" ]; then
                clear
            fi
            break 
            ;;
        *)
            echo "Opción inválida. Intente nuevamente."
    esac
done

