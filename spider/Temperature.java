package file;
import java.io.IOException;
import java.util.Scanner;

public class Temperature {
	static long Factorial( int n ) {
		if ( n == 1 || n == 2 ){
			return 1;
		}
		else {
			return Factorial(n-1) + Factorial(n-2);	
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		System.out.println("Input a number:");
		int n;
		Scanner cin = new Scanner(System.in);
		n = cin.nextInt();
		System.out.println(Factorial(n));	
	}
}
