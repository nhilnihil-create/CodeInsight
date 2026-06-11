#include <bits/stdc++.h>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

void comInit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    reps(i, MAX, 2)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll comb(ll n,ll k)
{
    if (n < k || n < 0 || k < 0)
    {
        return 0;
    }
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
comInit();
int n,p;
cin>>n>>p;
vector<int>a(n);
int odd=0,even=0;
rep(i,n){
    cin>>a[i];
    if(a[i]%2==0){
        even++;
    }
    else{
        odd++;
    }
}
ll ans=0;
rep(i,odd+1){
    if(p==0){
        if(i%2==0){
            ans+=comb(odd,i);
        }
    }
    else{
        if(i%2!=0){
            ans+=comb(odd,i);
        }
    }
}
ans*=pow(2,even);

cout<<ans<<endl;
return 0;
}