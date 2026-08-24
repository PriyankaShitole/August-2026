// Question 10

import java.util.*;

class AverageArray{
	
	public static void main(String args[]){

	int[] marks = new int[5];
	
	Scanner sc = new Scanner(System.in);

	for(int i=0; i<5; i++){

		System.out.print("Enter Number");
	
		marks[i] = sc.nextInt();
		}
	int avg = 0;
	for(int x : marks){

		avg = avg + x;
	}
		avg = avg/5;
		System.out.println(avg);
}
}