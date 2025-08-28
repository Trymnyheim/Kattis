// https://open.kattis.com/problems/testdrive

import java.util.Scanner;

public class testdrive {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] n = new int[3];
        for(int i = 0; i < n.length; i++) {
            n[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(findDrivingPattern(n));
    }

    private static String findDrivingPattern(int[] n) {
        int dist1, dist2;

        if ((n[0] < n[1] && n[1] > n[2]) || (n[0] > n[1] && n[1] < n[2])) {
            return "turned";
        }

        dist1 = Math.abs(n[1] - n[0]);
        dist2 = Math.abs(n[2] - n[1]);

        if (dist1 == dist2) {
            return "cruised";
        }
        else if (dist1 > dist2) {
            return "braked";
        }
        else {
            return "accelerated";
        }
    }
}