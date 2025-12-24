import java.util.Scanner;

public class alphabet {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String seq = scanner.nextLine();
        scanner.close();
        int longest = findLongest(seq);
        System.out.println("\n" + longest);
    }

    public static int findLongest(String seq) {
        int longest = 0, counter = 1;
        String prev = seq.charAt(0) + "";
        System.out.print(prev);
        String current;
        for (int i = 1; i < seq.length(); i++) {
            current = seq.charAt(i) + "";
            if (current.compareTo(prev) > 0) {
                counter++;
                System.out.print(current + "("+ counter+ ")");
            } else {
                if (counter > longest)
                    longest = counter;
                counter = 1;
                System.out.print();
            }
            prev = current;
        }
        return longest;
    }
}
