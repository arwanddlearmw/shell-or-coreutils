from livereload import Server

server = Server()

server.watch("*.html")
server.watch("*.css")
server.watch("*.js")
server.serve(host="0.0.0.0",port=5500,root=".")
