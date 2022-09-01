import java.util.Scanner;

class Student {
    String usn;
    String name;
    String branch;
    int phone;

    Student(String usn, String name, String branch, int phone) {
        this.usn = usn;
        this.name = name;
        this.branch = branch;
        this.phone = phone;
    }

    public static void main(String args[]) {
        Scanner S1 = new Scanner(System.in);

        Student s[] = new Student[5];
        String usn;
        String name;
        String branch;
        int n;
        int phone;
        System.out.println("enter the number of student");
        n = S1.nextInt();
        System.out.println("student details: usn\t name\t branch\t phone\t");
        for (int i = 0; i < n; i++) {
            usn = S1.next();
            name = S1.next();
            branch = S1.next();
            phone = S1.nextInt();
            s[i] = new Student(usn, name, branch, phone);
        }
        System.out.println("student details are");
        System.out.println("usn\t name\t branch\t phone\t ");
        for (int i = 0; i < n; i++) {
            System.out.println(s[i].usn + "\t" + s[i].name + "\t" + s[i].branch + "\t" + s[i].phone);
        }
        S1.close();
    }
}