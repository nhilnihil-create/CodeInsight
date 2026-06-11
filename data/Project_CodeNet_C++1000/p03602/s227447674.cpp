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

int main(){
    int n;cin>>n;
    ll a[n][n];
    ll ans=0;
    rep(i,n)rep(j,n){
        cin>>a[i][j];
        ans+=a[i][j];
    }
    rep(i,n)rep(j,n){
        bool ok=true;
        rep(k,n){
            if(a[i][j]>a[i][k]+a[k][j]){
                cout<<-1<<endl;
                return 0;
            }
            if(a[i][j]==a[i][k]+a[k][j]){
                if(i!=k&&k!=j)ok=false;
            }
        }
        if(!ok)ans-=a[i][j];
    }
    cout<<ans/2<<endl;;
    return 0;
}
