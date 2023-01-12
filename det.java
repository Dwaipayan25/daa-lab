/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    static void printArr(int a[][]){
        for(int i=0;i<a.length;i++){
            for(int j=0;j<a.length;j++){
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }
    }
    static int determinant(int arr[][]){
        int n=arr.length;
        if(n==1){
            return arr[0][0];
        }
        int det=0;
        for(int i=0;i<n;i++){
            int arr1[][] = new int[n-1][n-1];
            int row=0;
            for(int j=0;j<n;j++){
                if(j==i){
                    continue;
                }
                for(int k=1;k<n;k++){
                    arr1[row][k-1]=arr[j][k];
                }
                row++;
            }
            int wws=determinant(arr1)*arr[i][0];
            if(i%2==0){
                det=det+wws;
            }else{
                det=det-wws;
            }
        }
        return det;
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		int matrix[][]={{0,0,0},{0,0,0},{0,0,0}};
		int res=determinant(matrix);
		System.out.println("Determinant = "+res);
	}
}
/*
1 2 0
4 5 6
7 8 9
*/
