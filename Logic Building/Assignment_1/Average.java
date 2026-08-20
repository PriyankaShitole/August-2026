class Average{
	public static void main(String args[]){
	
	int math = 80;
	int science = 85;
        int history = 90;
        int avg = (math + science + history) / 3;
 	

	if (avg >= 90){
		System.out.println("grade A");
	}
	else if(avg >= 70 && avg<= 89){
		System.out.println("grade B");
	}
	else if(avg >= 50 && avg<= 69){
		System.out.println("grade C");
	}

	else if(avg >= 30 && avg<= 49){
		System.out.println("grade D");
 
	}
	else{
		
		System.out.println("Fail");
	}
}
}