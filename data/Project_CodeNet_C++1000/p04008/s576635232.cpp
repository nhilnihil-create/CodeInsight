#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


vector<int> v[101010];
int n,k,ans;

int solve(int x){
    int ret=0;
    for(auto to:v[x]){
        int res=solve(to);
        if(res>=k&&x!=0)ans++;
        else ret=max(res,ret);
    }
    return ret+1;
}

int main(){
    cin>>n>>k;
    int x;cin>>x;
    if(x!=1)ans++;
    rep(i,n-1){
        int x;cin>>x;
        v[x-1].push_back(i+1);
    }
    solve(0);
    cout<<ans<<endl;
    return 0;
}
