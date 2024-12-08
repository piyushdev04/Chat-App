# Socket Programming in C++

**Basic Steps in Socket Programming**
   The general flow of creating a socket-based application involves these steps:

   - **Socket Creation**: A socket is created using `socket()` function.
   - **Binding**: The server binds the socket to a local address and port using `bind()`.
   - **Listening**: The server listens for incoming connection requests with `listen()`.
   - **Accepting Connection**: The server accepts a client connection with `accept()`.
   - **Connecting**: The client connects to the server using `connect()`.
   - **Sending/Receiving Data**: Data is exchanged using `send()` and `recv()`.
   - **Closing Connection**: The connection is closed using `close()` or `closesocket()`.

**Common Winsock Functions**
   - **socket()**: Creates a socket.
   - **bind()**: Associates a socket with a specific IP address and port.
   - **listen()**: Puts the server socket in passive mode to accept incoming connections.
   - **accept()**: Accepts an incoming connection request.
   - **connect()**: Connects the client socket to a server.
   - **send()**: Sends data over the socket.
   - **recv()**: Receives data from the socket.
   - **closesocket()**: Closes the socket when done.