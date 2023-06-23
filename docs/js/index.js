function colormode() {
    if (document.body.classList.contains("dark")) {
        document.body.classList.replace("dark", "light")
        document.getElementById("clrmode").innerText = "Dark" 
    } else {
        document.body.classList.replace("light", "dark")
        document.getElementById("clrmode").innerText = "Light" 
    }
}