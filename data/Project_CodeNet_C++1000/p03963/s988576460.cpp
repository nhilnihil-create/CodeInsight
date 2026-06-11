#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll inf=1e18;
const int N=2e5+10;
ll factorial(ll x){
    if(x==0||x==1) return 1;
    return x*factorial(x-1);
}


int main(){
    int64_t n,k;
    cin >> n >> k;
    int64_t  ans=k;
    for(int i=1;i<n;++i) ans *= (k-1);

    cout<<ans<<endl;
    return 0;
}