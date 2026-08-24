//Question 7


import java.util.*;

class ArraySum{

	public static void main(String args[]){

	int[] marks = new int[5];
	
	Scanner sc = new Scanner(System.in);
	
	for(int i=0; i<5; i++){
		System.out.print("Enter Number "+ (i+1)+":");
		marks[i] = sc.nextInt();
	}
	int sum = 0;
	for(int x : marks){
		sum = sum + x;
	
	}
		System.out.println(sum);
}
}