#include<cstdio>

#define REP(i,n)   for(int i=0;i<(n);++i)
int b[100000];

int main(){
    int n,min=1e9+7,d=0,cnt=0;
    scanf("%d%*d",&n);
    REP(i,n) scanf("%d",b+i);
    REP(i,n){
        int a=b[i];
        if(min>a) min = a;
        else if(d==a-min) ++cnt;
        else if(d<a-min){
            d = a - min;
            cnt = 1;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
