// Question 9

import java.util.*;

class LargeElementArray{

	public static void main(String args[]){

	int marks[] = new int[5];

	Scanner sc = new Scanner(System.in);

	for(int i=0; i<5; i++){
		System.out.print("Enter Number " +(i+1)+ ":");
		marks[i] = sc.nextInt();
	
	}
	int larger = 0;
	for(int x : marks){

		if(larger < x){
		larger = x;
		}

	}
		System.out.println(larger);

}
}
	
         
		


