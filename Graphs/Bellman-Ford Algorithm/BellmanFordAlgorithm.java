import java.io.IOException;
import java.util.*;
public class BellmanFordAlgorithm {
  public static void main(String[] args) throws IOException {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    int m = scn.nextInt();
    int[][] matrix = new int[m][3];
    for (int i = 0; i
         < m; i++) {
      int u = scn.nextInt();
      int v = scn.nextInt();
      int w = scn.nextInt();
      matrix[i][0] = u - 1;
      matrix[i][1] = v - 1;
      matrix[i][2] = w;
    }
    int[] path = new int[n];
    Arrays.fill(path, Integer.MAX_VALUE);
    path[0] = 0;
    scn.close();
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j
           < m; j++) {
        int u = matrix[j][0];
        int v = matrix[j][1];
        int w = matrix[j][2];
        if (path[u] == Integer.MAX_VALUE) {
          continue;
        }
        if (path[u] + w < path[v]) {
          path[v] = path[u] + w;
        }
      }
    }
    for (int i = 1; i < path.length; i++) {
      if (path[i] == Integer.MAX_VALUE)
      {
        System.out.print( "1000000000" + " " );
      }
      else {
        System.out.print(path[i] + " " );
      }
    }
  }
}