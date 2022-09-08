import java.util.Scanner;

public class Kruskal1 {
    static int path[];
    static int n, m, costmin, i, j;

    public static void main(String[] args) {
        try (Scanner s = new Scanner(System.in)) {
            System.out.println(" Enter the no of vertices in a graph");
            n = s.nextInt();
            System.out.println("Enter  the no of edges");
            m = s.nextInt();
            path = new int[n + 1];
            Edge e[] = new Edge[m];
            Edge t = new Edge();
            for (i = 0; i < m; i++) {
                e[i] = new Edge();
                System.out.println("Enter the 2 vertices and weight of edge:");
                System.out.println("Enter the first vertex:");
                e[i].u = s.nextInt();
                System.out.println("Enter the Second vertex:");
                e[i].v = s.nextInt();
                System.out.println(" Weight:");
                e[i].wt = s.nextInt();
            }
            s.close();
            for (i = 0; i <= m - 1; i++) {
                for (j = 0; j < m - i - 1; j++) {
                    if (e[j].wt > e[j + 1].wt) {
                        t = e[j];
                        e[j] = e[j + 1];
                        e[j + 1] = t;
                    }
                }

            }
            for (i = 1; i <= n; i++) {
                path[i] = 0;
            }
            j = 0;
            i = 0;
            costmin = 0;
            System.out.println();
            while ((i != n - 1) && (j != m)) {
                System.out.print("Edge(" + e[j].u + "," + e[j].v + ")" + " weight " + e[j].wt + " ");
                if (Checkcycle(e[j])) {
                    costmin = costmin + e[j].wt;
                    i++;
                    System.out.println("is selected");
                } else {
                    System.out.println("is discarded");
                }
                j++;
            }
            if (i != n - 1) {
                System.out.println("Minimun cost spanning tree is formed");
            }
            s.close();
        }
    }

    public static boolean Checkcycle(Edge e) {
        int u = e.u, v = e.v;
        while (path[u] > 0)
            u = path[u];
        while (path[v] > 0)
            v = path[v];
        if (u != v) {
            path[u] = v;
            return true;
        }
        return false;
    }

    static class Edge {
        int u, v, wt;
    }

}
