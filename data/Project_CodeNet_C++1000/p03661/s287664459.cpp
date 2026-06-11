#include<bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
using LL = long long;
const LL LINF = 1e18;
using namespace std;
#define COUT(v) cout<<(v)<<endl
#define CIN(n)  int(n);cin >> (n)
#define YES(n) cout<<((n)? "YES" : "NO")<<endl
#define Yes(n) cout<<((n)? "Yes" : "No")<<endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) <<endl

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)

#define FOREACH(x,a) for(auto& (x) : (a) )

#define ALL(obj) (obj).begin(),(obj).end()

#define P pair<int,int>
#define I vector<int>
#define S set<int>
#define pb(v) push_back(v)
#define V vector
#define rt return
LL rui[1000000];
int main(){
    CIN(N);
    V<LL> vec;
    REP(a,N){
      CIN(b);vec.pb(b);
      rui[a+1]+=rui[a]+b;
    }
    LL ans = LINF;
    FOR(a,1,N){
       ans = min(ans,abs(rui[N]-(rui[a]*2)));
    }
    COUT(ans);
    return 0;
}
