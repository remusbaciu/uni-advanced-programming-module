## Task 2 - Client configuration

In order to start up the client application

Go to the following class and run the main method

``src/main/java/App.java``

Running the main method inside App.java, should open up connect to a socket on port 5001.

If you want to connect a client to this server, both must be pointing to the same port.

NOTE: When the client is initialised, the server must already have a socket opened at the correct port,
otherwise, an exception will be thrown (Connection refused);