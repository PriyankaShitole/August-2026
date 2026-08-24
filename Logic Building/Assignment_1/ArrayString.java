//Question 8


import java.util.*;

class ArrayString{

	public static void main(String args[]){

	String[] marks = new String[5];
	
	Scanner sc = new Scanner(System.in);
	
	for(int i=0; i<5; i++){
		System.out.print("Enter Number "+ (i+1)+":");
		marks[i] = sc.next();
	}
	
	for(String x : marks){
		System.out.println(x);
        }
}
}