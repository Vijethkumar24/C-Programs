import java.util.Scanner;

public class KnapSack {
    public static void main(String[] args) {
        float w[] = new float[20];
        float v[] = new float[20];
        float ratio[] = new float[20];
        float temp;
        int n, i, j;
        float W;
        try (Scanner s = new Scanner(System.in)) {
            System.out.println("Enter the no of object");
            n = s.nextInt();
            for (i = 0; i < n; i++) {
                System.out.println("enter the weight and value for the object " + (i + 1));
                w[i] = s.nextFloat();
                v[i] = s.nextFloat();
            }

            System.out.println("Enter the maximum capacity of the bag");
            W = s.nextFloat();
            for (i = 0; i < n; i++) {
                ratio[i] = (v[i] / w[i]);

            }
            for (i = 0; i < n; i++) {
                for (j = i + 1; j < n; j++) {
                    if (ratio[i] < ratio[j]) {
                        temp = ratio[j];
                        ratio[j] = ratio[i];
                        ratio[i] = temp;
                        temp = w[j];
                        w[j] = w[i];
                        w[i] = temp;
                        temp = v[j];
                        v[j] = v[i];
                        v[i] = temp;

                    }
                }
            }
            KnapSack k = new KnapSack();
            k.Knapsack(n, w, v, W);
            s.close();
        }

    }

    private void Knapsack(int n, float[] w, float[] v, float w2) {
        float x[] = new float[20], tp = 0;
        int u, i;
        for (i = 0; i < n; i++)
            x[i] = 0;
        u = (int) w2;
        for (i = 0; i < n; i++) {
            if (w[i] > u)
                break;
            else {
                x[i] = 1;
                tp = tp + v[i];
                u = (int) (u - w[i]);
            }

        }
        if (i < n)
            x[i] = u / w[i];
        tp = tp + (x[i] * v[i]);
        System.out.println("weight");
        for (i = 0; i < n; i++) {
            System.out.print(w[i] + "\t");

        }
        System.out.println();
        System.out.println("Value");
        for (i = 0; i < n; i++) {
            System.out.print(v[i] + "\t");
        }
        System.out.println();
        System.out.println("x");
        for (i = 0; i < n; i++) {
            System.out.print(x[i] + "\t");

        }
        System.out.println();
        System.out.println("Maximum value we can get is " + tp);
    }
}
