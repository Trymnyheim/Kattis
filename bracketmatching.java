// https://open.kattis.com/problems/bracketmatching

import java.util.Scanner;
import java.util.Stack;

public class bracketmatching {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int length = scanner.nextInt();
        scanner.nextLine(); // consume leftover newline
        String seq = "";
        if (length != 0) {
            seq = scanner.nextLine();
        }
        scanner.close();

        if (matchBrackets(length, seq))
            System.out.println("valid");
        else
            System.out.println("invalid");
    }

    public static boolean matchBrackets(int len, String seq) {
        if (len == 0) return true;
        if (len == 1) return false;

        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < len; i++) {
            char c = seq.charAt(i);

            // opening brackets go on stack
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else { 
                // closing bracket, must match top
                if (stack.isEmpty()) return false; // too many closings
                char opening = stack.pop();
                if (!isMatch(opening, c)) return false;
            }
        }
        // all openings should be closed
        return stack.isEmpty();
    }

    public static boolean isMatch(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '[' && close == ']') ||
               (open == '{' && close == '}');
    }
}

