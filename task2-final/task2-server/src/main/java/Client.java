import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.*;

public class Client extends Communications {

    Socket socket;
    Thread thread1, thread2;

    public Client(String address, int port) {
        try {
            thread1 = new Thread(this);
            thread2 = new Thread(this);
            socket = new Socket(address, port);
            thread1.start();
            thread2.start();
        } catch (IOException io) {
           System.out.println("Error initialising connection socket on: " + address + ":" + port);
           io.printStackTrace();
        }
    }

    public void run() {
        BufferedReader bufferedReader;
        PrintWriter printWriter;
        String input = "";
        String output = "";
        try {
            if (Thread.currentThread() == thread2) {
                while (!input.equals("QUIT")) {
                    printWriter = new PrintWriter(socket.getOutputStream(), true);
                    bufferedReader = new BufferedReader(new InputStreamReader(System.in));
                    input = bufferedReader.readLine();
                    printWriter.println(input);
                };
            } else {
                while (!output.equals("QUIT")) {
                    bufferedReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                    output = bufferedReader.readLine();
                    System.out.println("Message from the server: " + output);
                };
            }
        } catch (IOException io) {
            System.out.println("Client has encountered issues while trying to communicate with the server");
            io.printStackTrace();
        }
    }
}