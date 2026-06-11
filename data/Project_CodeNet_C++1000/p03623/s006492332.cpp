#include<stdio.h>
int main()
{
int X,A,B;
int XA,XB;
scanf("%d %d %d", &X, &A, &B);
XA = A - X;
XB = B - X;
XA < 0 ? XA = XA* -1 : XA = XA * 1;
XB < 0 ? XB = XB* -1 : XB = XB * 1;
XA < XB ? printf("A\n") : printf("B\n");
return 0;
}
