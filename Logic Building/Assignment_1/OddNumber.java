// question 5

import java.util.Scanner;

class OddNumber{


	public static void main(String args[]){

	Scanner sc = new Scanner(System.in);
	System.out.print("Enter Number : ");
	int num = sc.nextInt();

	for(int i=1; i<=num; i++){

		if(i % 2 != 0)

			System.out.println(i);
	}
}
}