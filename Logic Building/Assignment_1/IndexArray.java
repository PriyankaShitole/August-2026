//Question 14

import java.util.*;

class IndexArray{

	public static void main(String args[]){


	int[] num = new int[5];

	Scanner sc = new Scanner(System.in);

	for(int i=0; i<5; i++){
		System.out.print("Enter Number");
		num [i] = sc.nextInt();
	}
	
	int search;
	

	System.out.print("Enter Number to search : ");
	search = sc.nextInt();
	
	for(int i=0; i<5; i++){
		if(num [i] == search){
			System.out.print(i);

		}
        }
}
}

