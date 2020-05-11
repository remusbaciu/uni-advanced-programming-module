public class App {

    public static void main(String[] args) {
        System.out.println("Initialising communication connection for the client");
        new Client("localhost",5001);
    }
}
