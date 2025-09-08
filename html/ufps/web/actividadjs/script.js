// 🟢 DESAFÍO 1: Cambiar el texto de un párrafo al hacer clic en el botón
document.getElementById("btnTexto").addEventListener("click", function () {
    const btn = document.getElementById("texto")
    btn.innerText = "¡Texto cambiado!"
});

// 🟢 DESAFÍO 2: Alternar el color de fondo de la página al hacer clic
document.getElementById("btnColor").addEventListener("click", function () {
    const body = document.querySelector("body")
    body.classList.toggle("bg-gray-100")
    body.classList.toggle("bg-[#00afc7]")
    //body.style.background = "#350080ff"
});

// 🟢 DESAFÍO 3: Agregar tareas dinámicamente a la lista
let tareaId = 1
document.getElementById("btnAgregar").addEventListener("click", function () {
    const intareas = document.getElementById("inputTarea")
    const valor = intareas.value
    if(valor.trim() === "") return  
    crearTarea(tareaId, valor)
    localStorage.setItem(tareaId, valor)
    intareas.value = ""
    tareaId++
});

function crearTarea(id, contenido){
    const list = document.getElementById("listaTareas")
    const item = document.createElement("li")
    const btn = document.createElement("button")
    btn.innerText = "X"
    const myId = id
    btn.className = "bg-emerald-500 h-10 w-10 rounded-full text-[#350080] text-center font-bold rounded hover:bg-blue-800"
    btn.addEventListener("click", function () {
        item.remove()
        localStorage.removeItem(myId)
    })

    item.innerText = contenido
    item.className = "bg-violet-400 px-5 py-1 flex justify-between items-center rounded-full"
    item.appendChild(btn)
    list.appendChild(item)
}


// 🟢 DESAFÍO 4: Cargar datos de usuarios desde una API pública
//Lo que está comentado es el encargado de listar de manera aleatoria
//lo que no filtra los usuarios de acuerdo a lo indicado en el desafío 6

// 🟢 DESAFÍO 6 (Extra): Filtrar usuarios con correos que contengan "biz"
//funcion para filtrar
function filtraje(persona){
    let size = persona.email.length
    return persona.email[size-1] == "z" && persona.email[size-2] == "i" && persona.email[size-3] == "b"
}
document.getElementById("btnUsuarios").addEventListener("click", function () {
    // let num = Math.floor(Math.random() *10)
    const users = document.getElementById("listaUsuarios")
    users.replaceChildren() //comentarear esta linea si va a enlistar de manera aleatoria
    fetch('https://jsonplaceholder.typicode.com/users').then((Response) => Response.json()).then(data => {
        // usuario = document.createElement("li")
        // ñame = document.createElement("div")
        // email = document.createElement("div")
        // usuario.className = "bg-[#2e97bd] flex justify-between p-2 rounded-lg "
        // ñame.innerText = data[num].name
        // email.innerText = data[num].email
        // usuario.appendChild(ñame)
        // usuario.appendChild(email)
        // users.appendChild(usuario)
        const filtro = data.filter(filtraje)
        for(const persona of filtro){
            const usuario = document.createElement("li")
            const ñame = document.createElement("div")
            const email = document.createElement("div")
            usuario.className = "bg-[#2e97bd] flex justify-between p-2 rounded-lg "
            ñame.innerText = persona.name
            email.innerText = persona.email
            usuario.appendChild(ñame)
            usuario.appendChild(email)
            users.appendChild(usuario)
        }
    });
})

// 🟢 DESAFÍO 5 (Extra): Guardar y cargar la lista de tareas usando localStorage
window.addEventListener("DOMContentLoaded", function () {
    for (let i = 0; i < localStorage.length; i++) {
        const key = localStorage.key(i);
        const value = localStorage.getItem(key);
        crearTarea(key, value);
        if (+key >= tareaId) {
            tareaId = +key + 1;
        }
    }
})

