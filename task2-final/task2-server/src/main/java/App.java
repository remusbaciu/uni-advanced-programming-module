public class App {

    public static void main(String[] args) {
        System.out.println("Initialising communication connection for the server");
        new Server(5001);
    }
}
