// question 30

class StringIntern{

	public static void main(String args[]){

	String str1 = new String("hello");
	String str2 = str1.intern();
	String str3 = "hello";

	System.out.println(str2==str3);
	}
}