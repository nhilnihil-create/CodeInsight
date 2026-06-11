#include<cstdio>
#include<iostream>

#define REP(i,n)   for(int i=0;i<(n);++i)

int main(){
    int n,a,min=1234567899,d=0,cnt=0;
    scanf("%d%*d",&n);
    REP(i,n){
        //scanf("%d",&a);
        std::cin >> a;
        if(min>a){
            min = a;
        }else if(d==a-min){
            ++cnt;
        }else if(d<a-min){
            d = a - min;
            cnt=1;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
