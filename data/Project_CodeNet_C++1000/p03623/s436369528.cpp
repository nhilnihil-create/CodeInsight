#include <stdio.h>

int main(){
int x, a, b, d1=-1, d2=-2 ;
scanf("%d %d %d", &x, &a, &b);
d1=x-a ;
d2=x-b ;
if(d1<0){
    d1=a-x;
}
if(d2<0){
    d2=b-x;
}

d1<d2? printf("A") : printf("B");
return 0;
}
