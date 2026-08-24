//Question 13

import java.util.*;

class SpecificElement{

		public static void main(String args[]){

		int[] num = new int[5];

		Scanner sc = new Scanner(System.in);

		for(int i=0; i<5; i++){
			System.out.print("Enter Number"+(i+1)+ ":");
			num[i] = sc.nextInt();
		}


		
		int search;

		System.out.print("Enter Number to Search : ");
		search = sc.nextInt();
		boolean found = false;
		for(int x : num){
			
		   if(x==search){
			found = true;
			break;
			}

		}
		if(found){
			System.out.print("Found");
		}
		else{
			System.out.print("Not Found");
				
		}

}	
}
			
