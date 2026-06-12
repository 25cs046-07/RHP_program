import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        int q = sc.nextInt();

        int M = 200000;

        int[] d = new int[M + 2];

        for (int i = 0; i < n; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            d[l]++;
            d[r + 1]--;
        }

        int[] f = new int[M + 1];
        for (int i = 1; i <= M; i++) {
            f[i] = f[i - 1] + d[i];
        }

        int[] ok = new int[M + 1];
        for (int i = 1; i <= M; i++) {
            if (f[i] >= k) ok[i] = 1;
        }

        int[] pre = new int[M + 1];
        for (int i = 1; i <= M; i++) {
            pre[i] = pre[i - 1] + ok[i];
        }

        while (q-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            System.out.println(pre[b] - pre[a - 1]);
        }
    }
}
