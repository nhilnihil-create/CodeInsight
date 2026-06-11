#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#include <cctype>
#include <locale>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<long long,long long> Pll;
#define fout(num) cout << fixed << setprecision(20) << (num) << endl
//s[i]=tolower(s[i]); islower(s[i]); cout << tolower(s[i])はバグ
//vector<vector<ll>> dp(n,vector<ll>(n))
//exist x map o setconst ll MOD = 1e9+7;return fac[n]*(finv[k]*finv[n-k] % MOD) % MOD;
//2-dim:vector<vector<Type>> vv(n, vector<Type>(m, d));
//3-dim:vector<vector<vector<Type>>> vvv(n, vector<vector<Type>>(m, vector<Type>(l, d)));

const ll MOD = 1e9+7;
const int MAX = 1001001;
ll fac[MAX],finv[MAX],inv[MAX];
void COMinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i % MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i) % MOD;
        finv[i]=finv[i-1]*inv[i] % MOD;
    }
}
ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0 || k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k] % MOD) % MOD;
}
signed main(){
    COMinit();
    int n; cin >> n;
    int p; cin >> p;
    int num[2]={0,0};
    rep(i,n){
        int a; cin >> a;
        a%=2;
        num[a]++;
    }
    if(p==0){
        ll ans=(1ull<<num[0]);
        ll res=1;
        for(int i=2;i<=num[1];i+=2){
            res+=COM(num[1],i);
        }
        ans*=res;
        cout << ans << endl;
    }else{
        ll ans=(1ull<<num[0]);
        ll res=0;
        for(int i=1;i<=num[1];i+=2){
            res+=COM(num[1],i);
        }
        ans*=res;
        cout << ans << endl;
    }
}


