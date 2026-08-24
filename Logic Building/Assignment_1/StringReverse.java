//Question 24

import java.util.*;

class StringReverse{

	public static void main(String args[]){

	Scanner sc = new Scanner(System.in);

	System.out.print("Enter A String :");
	String str = sc.nextLine();

	String rev = "";

	for(int i=str.length()-1; i>=0; i--){

		rev = rev + str.charAt(i);
	}

	System.out.println("Reverse String : " + rev);
	
}
}

	
