// Question 6

import java.util.*;


class Array{

	public static void main(String args[]){

	int[] marks = new int[5];
        Scanner sc = new Scanner(System.in);
	
	for(int i=0; i<5; i++){
 	System.out.print("Enter Number " + (i+1) + " :");

	 marks[i] = sc.nextInt();
	}
	
	for(int x : marks){
                System.out.print(x + " ");
		
	}
}
}