#include <cstdio>
int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int first= a*b;
    int second=c*d;
    if(first>=second){
        printf("%d",first);
    }
    else{
        printf("%d",second);
    }
}
