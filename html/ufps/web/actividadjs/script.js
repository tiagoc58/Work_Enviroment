// 🟢 DESAFÍO 1: Cambiar el texto de un párrafo al hacer clic en el botón
document.getElementById("btnTexto").addEventListener("click", function () {
    // TODO: Seleccionar el párrafo con id "texto" y cambiar su contenido a "¡Texto cambiado!"
    const btn = document.getElementById("texto")
    btn.innerText = "¡Texto cambiado!"
});

// 🟢 DESAFÍO 2: Alternar el color de fondo de la página al hacer clic
document.getElementById("btnColor").addEventListener("click", function () {
    // Lectura recomendada: https://developer.mozilla.org/en-US/docs/Web/API/DOMTokenList/toggle
    // TODO: Usar classList.toggle() para alternar un fondo diferente en el body
    const body = document.querySelector("body")
    body.classList.toggle("bg-gray-100")
    body.classList.toggle("bg-[#00afc7]")
    //body.classList.toggle("bg-blue")
    //body.style.background = "#2ebd8bff"
    //body.className = "bg-[#00afc7] flex flex-col items-center justify-center min-h-screen p-5"
});

// 🟢 DESAFÍO 3: Agregar tareas dinámicamente a la lista
document.getElementById("btnAgregar").addEventListener("click", function () {
    // TODO: Leer el valor del input "inputTarea"
    // TODO: Crear un nuevo <li> y agregarle el texto ingresado
    // TODO: Agregar un botón dentro del <li> para eliminar la tarea
    // TODO: Agregar el <li> a la lista "listaTareas"
    const intareas = document.getElementById("inputTarea")
    const list = document.getElementById("listaTareas")
    const item = document.createElement("li")
    const contenedor = document.createElement("div")
    const valor = intareas.value
    if(valor.trim() === "") return
    contenedor.innerText = valor
    contenedor.className = "text-center"
    const btn = document.createElement("button")
    btn.className = "bg-sky-400 px-4 py-2 text-white rounded hover:bg-blue-800"
    btn.innerText = "Eliminar tarea"
    btn.addEventListener("click", function () {
        item.remove()
    })
    item.className = "bg-violet-400 flex justify-between rounded"
    item.appendChild(contenedor)
    item.appendChild(btn)
    list.appendChild(item)
    intareas.value = ""
});


// 🟢 DESAFÍO 4: Cargar datos de usuarios desde una API pública
document.getElementById("btnUsuarios").addEventListener("click", function () {
    // Lectura recomendada: https://developer.mozilla.org/es/docs/Web/API/Fetch_API/Using_Fetch
    // TODO: Hacer una petición a "https://jsonplaceholder.typicode.com/users"
    // TODO: Mostrar solo los nombres y correos electrónicos en "listaUsuarios"
    // TODO: Si la petición falla, mostrar un mensaje de error en consola
});

// 🟢 DESAFÍO 5 (Extra): Guardar y cargar la lista de tareas usando localStorage
// Lectura recomendada: https://developer.mozilla.org/en-US/docs/Web/API/Window/localStorage
// TODO: Guardar las tareas en localStorage cada vez que se agregue o elimine una
// TODO: Cargar las tareas desde localStorage cuando la página se recargue

// 🟢 DESAFÍO 6 (Extra): Filtrar usuarios con correos que contengan "biz"
// Lectura recomendada: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/filter
// TODO: Modificar el código del desafío 4 para mostrar solo usuarios con "@biz" en su email
