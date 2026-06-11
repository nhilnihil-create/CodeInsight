// CODE by Kazhybay Askar

//#include <ext/pb_ds/assoc_cont ainer.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC    optimize("Ofast")
//#pragma GCC    target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define f      first
#define s      second
#define pb     push_back
#define pf     push_front
#define ppb    pop_back
#define ppf    pop_front
#define Speed  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define sz     size()
#define all(x) x.begin(),x.end()
#define cont   continue
#define r0     return 0
#define endl   '\n'

typedef long long ll;
typedef long double   ld;
typedef pair<ll,ll>   pll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;

const int MAXN  = 5e5  + 7;
const int MOD   = 1e9  + 7;
const int INF   = 1e9  + 7;
const ll  MINF  = 1e18 + 7;
const int EPS   = 1e-6;
const int dx[]  = {0, 0, 1, -1, -1, -1, 1, 1};
const int dy[]  = {1, -1, 0, 0, -1, 1, -1, 1};
const double pi = acos(-1.0);

ll n,a,b,c,d;

void solve(){
    cin>>n>>a>>b>>c>>d;
    if(abs(a-b)>(n-1)*d){
        cout<<"NO";
        return;
    }
    for(int i=1;i<=n;i++){
        ll x=n-i-1;
        if(a+d*i - c*x>=b && a+c*i-d*x<=b){
            cout<<"YES";
            return ;
        }
    }
    cout<<"NO";
}



int main(){
    Speed;
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    r0;
}


