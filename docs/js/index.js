function colorscheme() {
    colorbtn = document.getElementById("colorscheme")
    if (document.body.classList.contains("dark")) {
        document.body.classList.replace("dark", "light")
        colorbtn.innerText = "Dark" 
    } else {
        document.body.classList.replace("light", "dark")
        colorbtn.innerText = "Light" 
    }
}