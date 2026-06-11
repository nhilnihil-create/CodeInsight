 #include<stdio.h>
 int main(void)
 {
    char N[100];
    int i;

     scanf("%s",N);

    if(N[0]==N[2])
      printf("Yes\n");
    else
      printf("No\n");

    return 0;
 }