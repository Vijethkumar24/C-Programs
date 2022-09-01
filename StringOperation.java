import java.util.Scanner;

public class StringOperation {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        System.out.println("Enter the name of 1st person");
        String name1 = scan.nextLine();
        int length1 = name1.length();
        System.out.println("String Length:" + name1.length());
        System.out.println();
        System.out.println("Enter the name of 2nd person");
        String name2 = scan.nextLine();
        int length2 = name2.length();
        System.out.println("String Length: " + name2.length());
        System.out.println();
        String name3 = name1 + " " + name2;
        System.out.println("String Afer Concatination:\n");
        System.out.println(name3);
        System.out.println("String Length After Concatination:" + name3.length());
        System.out.println();
        int m = 0;
        if (length1 == length2) {
            for (int i = Math.max(length1, length2) - 1; i >= 0; i--) {
                if (name1.charAt(i) == name2.charAt(i)) {
                    m++;
                }
            }
        }
        if (m == length1 && m == length2)
        {
            System.out.println("Strings are equal");
            System.out.println("Number Of String Matched\n"+m);
        }
        else
        {
            System.out.println("Strings are Different ");
            System.out.println("Number Of String Matched\n"+m);
            System.exit(0);
        }

       

        scan.close();
    }
}
