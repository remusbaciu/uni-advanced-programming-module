import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.*;

public class Server extends Communications {

    Socket socket;
    Thread thread1 = new Thread(this);
    Thread thread2 = new Thread(this);
    String input = "", output = "";

    public Server(int port) {
        try {
            ServerSocket serverSocket = establishSocketConnection(port);
            socket = serverSocket.accept();
            System.out.println("Client connected with Ip " + socket.getInetAddress().getHostAddress());
            thread1.start();
            thread2.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void run() {
        BufferedReader bufferedReader;
        PrintWriter printWriter;
        try {
            if (Thread.currentThread() == thread1) {
                while (!input.equals("QUIT"))  {
                    bufferedReader = new BufferedReader(new InputStreamReader(System.in));
                    printWriter = new PrintWriter(socket.getOutputStream(), true);
                    input = bufferedReader.readLine();
                    printWriter.println(input);
                };
            } else {
                while (!output.equals("QUIT")) {
                    bufferedReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                    output = bufferedReader.readLine();
                    System.out.println("Message from the client: " + output);
                };
            }
        } catch (IOException e) {
            System.out.println("Server has encountered issues while trying to communicate with the client");
            e.printStackTrace();
        }
    }

    public ServerSocket establishSocketConnection(int port) throws IOException {
        ServerSocket serversocket = new ServerSocket(port);
        System.out.println("Server socket has been created and is waiting for connections on port: " + port);
        return serversocket;
    }
}