#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;


int main(){
    LL K;
    cin >> K;
    puts("50");
    LL t=K/50+49;
    for(int i=0;i<50;i++){
        if(K%50==0) cout << t << (i==49?"\n":" ");
        else if(i>=50-K%50) cout << t+1 << (i==49?"\n":" ");
        else cout << t-K%50 <<" ";
    }
    return 0;
}