import java.util.Scanner;
import java.util.Arrays;
public class SieveOfEratosthenes {
	public static void main(String args[]) {
		int number;
		Scanner reader = new Scanner(System.in);
		System.out.println("please enter the number upto which you want the prime numbers");
		number = reader.nextInt();
		int sieveArray[] = new int[number + 1];
		Arrays.fill(sieveArray, 1); //initialize all indices with 1
		for (int i = 2; i <= Math.sqrt(number); i ++) {
			for (int j = 2; j * i <= number; j ++) {
				sieveArray[j * i] = 0;
			}
		}
		System.out.println("The prime numbers upto " + number + " are: ");
		for (int i = 2; i <= number; i ++) {
			if (sieveArray[i] == 1) {
				System.out.println(i);
			}
		}
	}
}