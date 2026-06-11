#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

vector<long long> fact, fact_inv, inv;   //fact[i]=i!                       nが10^7より大きいと配列が大きすぎる？
void init_nCk(int SIZE) {                //inv[i]=i^(-1)           
    fact.resize(SIZE + 5);               //fact_inv[i]=inv[i]の累積積
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);
    fact[0] = fact[1] = 1;                          
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < SIZE + 5; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
    }
}

long long nPk(int n, int k) {
    return (fact[n] * fact[n-k]) % mod;
}

int main(){
    init_nCk(510000);
    int n,m;
    cin>>n>>m;
    int ans,x;
    if(abs(n-m)>1){
        cout<<0<<endl;
        return 0;
    }
    else if(abs(n-m)==1) x=1;
    else x=2;
    cout<<x*nPk(n,n)%mod*nPk(m,m)%mod<<endl;
return 0;
}