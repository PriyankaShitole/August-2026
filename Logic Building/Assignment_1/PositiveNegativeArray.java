// Question 11

import java.util.*;

class PositiveNegativeArray{

	public static void main(String args[]){

	int[] num = new int[6];
	Scanner sc = new Scanner(System.in);

	for(int i=0; i<6; i++){
		System.out.println("Enter Number "+ (i+1) + ":");
		num[i] = sc.nextInt();
	}
	int Positive = 0;
	int Negative = 0;
	for(int x : num){
		if(x>0)
		Positive++;
			
		else
		Negative++;			
			
	}
	
		System.out.println("Positive Number " + Positive);
			
		System.out.println("Negative Number " + Negative);
}
}
