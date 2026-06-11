 #include<stdio.h>
 #include<string.h>

  int main(void)
  {
   char A[11],B[11],C[11];

   scanf("%s%s%s",A,B,C);

   int ae = strlen(A);
   int be = strlen(B);

   if(A[ae-1]==B[0]&&B[be-1]==C[0])
     printf("YES\n");
   else
     printf("NO\n");

   return 0;
  }
