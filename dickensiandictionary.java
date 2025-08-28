// https://open.kattis.com/problems/dickensiandictionary

import java.util.Scanner;

public class dickensiandictionary {

    static final String LEFT = "qwertasdfgzxcvb";
    static final String RIGHT = "yuiophjklnm";
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String word = scanner.nextLine();
        scanner.close();
        System.out.println(isDickensian(word));
    }

    public static String isDickensian(String word) {
        boolean isRight;
        boolean wasRight = RIGHT.contains("" + word.charAt(0));
        int i = 1;
        do {
            isRight = RIGHT.contains("" + word.charAt(i));
            if (isRight == wasRight)
                return "no";
            wasRight = isRight;
            i++;
        } while (i < word.length());
        return "yes";
    }
}
