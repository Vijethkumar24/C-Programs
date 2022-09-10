import java.util.Scanner;

public class Dijkstras {
    private int[][] cost = new int[10][10];
    public int distance[] = new int[10];

    public static void main(String[] args) {
        int n;
        int s, i, j;
        Scanner sc = new Scanner(System.in);
        Dijkstras d = new Dijkstras();
        System.out.println("Enter the number of nodes");
        n = sc.nextInt();
        System.out.println("Enter the cost matrix");
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++) {//
                d.cost[i][j] = sc.nextInt();
                if (d.cost[i][j] == 0)
                    d.cost[i][j] = 9999;
            }
        System.out.println("enter the soure vertex ");
        s = sc.nextInt();
        d.calculate(n, s);
        System.out.println("The shortest path from Source:" + s + " to all other vertices are");
        for (i = 1; i <= n; i++) {
            if (i != s) {
                System.out.println("Source: " + s + "\t" + "Destination: " + i + "\t" + "MinCost: " + d.distance[i]);
            }
        }

    }

    private void calculate(int n, int s) {
        int i, minpos = 1, Minimun, k, c;
        int flag[] = new int[n + 1];
        for (i = 1; i <= n; i++) {
            flag[i] = 0;
            this.distance[i] = this.cost[s][i];
        }
        c = 2;
        while (c <= n) {
            Minimun = 99;
            for (k = 1; k <= n; k++) {
                if (this.distance[k] < Minimun && flag[k] != 1) {
                    Minimun = this.distance[i];
                    minpos = k;
                }
            }
            flag[minpos] = 1;
            c++;
            for (i = 1; i <= n; i++) {
                if (this.distance[minpos] + this.cost[minpos][k] < this.distance[k] && flag[k] != 1) {
                    this.distance[k] = this.distance[minpos] + this.cost[minpos][k];
                }
            }
        }
    }
}
