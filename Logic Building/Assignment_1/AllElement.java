import java.util.Scanner;
import java.util.Arrays;

class AllElement {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        int[] number = new int[4];

        for(int i = 0; i < 4; i++) {
            System.out.println("Enter Number " + (i + 1) + " : ");
            number[i] = sc.nextInt();
        }

        System.out.println(Arrays.toString(number));
    }
}