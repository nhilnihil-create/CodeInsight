#include<bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
long long INF = 1e18;
const int mod = 1e9 + 7;

using namespace std;

int main(){
    int n,a,min=mod,d=0,cnt=0;
    scanf("%d%*d",&n);
    REP(i,n){
        scanf("%d",&a);
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
