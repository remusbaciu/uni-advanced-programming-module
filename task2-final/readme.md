This projects contain 2 submodules

- task2-server
- task2-client

They have been configured to start or listen on a specific port for messages.

Each module has a README.md file inside them, explaining how to start each individual one up.

In order to have a succesful run, please start the server first, as it will open up a socket on a specific port, and then start up the client as the second one, as it will try to connect to a socket that should already exist.

Java does well at handling exceptions, but I have created catchers for specific expcetion that might be thrown, and added readable text.

I have added screenshots of happy path execution whoch can be found at the root level of this submission directory.