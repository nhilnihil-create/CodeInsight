#include <stdio.h>
int main(){int a,b;scanf("%d%d",&a,&b);if(a<=0&&0<=b) printf("Zero");else if(a>0||(b-a)%2==1) printf("Positive");else printf("Negative");}