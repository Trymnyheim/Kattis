// https://open.kattis.com/problems/cinema

import java.util.Scanner;

public class cinema {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();
        scanner.nextLine();

        int filled = 0, leftOut = 0;
        int group;
        for (int i = 0; i < M; i++) {
            group = scanner.nextInt();
            if (filled < N && filled + group <= N)
                filled += group;
            else
                leftOut++;
        }
        scanner.close();
        System.out.println(leftOut);
    }
}
