import java.util.Scanner;

public class LabProgram {
    public static void main(String[] args) 
    {
      Scanner scnr = new Scanner(System.in);
      int n;
      n = scnr.nextInt();
      int[] matrixA = new int[n]; // Matrix A
      int[][] matrixB = new int[n][n]; // Matrix B
      int[] matrixC = new int[n]; // Matrix C
        
      /* Type your code here. */
        
      int i, j, k;
        
      for(i = 0; i < n; i++)
      {
         matrixA[i] = scnr.nextInt();
      }
        
      for(i = 0; i < n; i++)
      {
         for(j = 0; j < n; j++)
         {
            matrixB[i][j] = scnr.nextInt();
         }
      }
        
      for(i = 0; i < n; i++)
      {
         matrixC[i] = 0;
            
         for(j = 0; j < 1; j++)
         {
            for (k = 0; k < n; k++) 
            {
               matrixC[i] = matrixC[i] + (matrixA[k] * matrixB[k][i]);
            }
         }
      }
        
      for(i = 0; i < n; i++)
      {
         System.out.print(matrixC[i] + " ");
      }
        
      System.out.println(); 
   }
}