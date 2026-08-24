//Question 12

import java.util.*;

class AscendingOrder{

	public static void main(String args[]){

	int[] order = new int[5];
	
	Scanner sc = new Scanner(System.in);

	for(int i=0; i<5; i++){
		System.out.println("Enter Number " + (i+1) + " :");
		order[i] = sc.nextInt();

	}
		for(int i=0; i<5; i++){
		    for(int j = i + 1; j < 5; j++){
		
			if(order[i] > order[j]){
    			int temp = order[i];
    			order[i] = order[j];
   			order[j] = temp;
                        }
	            }
               }
	for(int x : order){
        System.out.println(x);
        }
}
}
		
			