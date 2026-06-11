#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<vector>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;
const double EPS=1e-7;

ll N,A,B;
ll v[100];
ll nCk(ll n, ll k) {
  ll ans = 1;
  for (ll i = n, j = 1; j <= k; i--, j++) ans = (ans * i/j) ;
  return ans;
}
ll C[100][100];
void nCkInit(){
    for(int i=0;i<=N;++i){
        for(int j=0;j<=i;++j){
            if(j==0 || j==i){
                C[i][j]=1LL;
            }else{
                C[i][j]=(C[i-1][j-1]+C[i-1][j]);
            }
        }   
    }
}
int main(){
    cin>>N>>A>>B;
    for(ll i=0;i<N;i++){
        cin>>v[i];
    }
    sort(v,v+N,greater<ll>());
    ll allCnt=0;
    for(ll i=0;i<N;i++){
        if(v[i]==v[A-1]){
            allCnt++;
        }
    }
    double ave=0;
    ll innerCnt=0;
    for(ll i=0;i<A;i++){
        ave+=v[i];
        if(v[i]==v[A-1]){
            innerCnt++;
        }
    }
    ave/=A;
    cout<<setprecision(10)<<ave<<endl;

    if(v[0]==v[A-1]){
        ll ans=0;
        for(ll i=A;i<=B;i++){
            ans+=nCk(allCnt,i);
            //ans+=C[allCnt][i];
        }
        cout<<ans<<endl;
    }else{
        cout<<nCk(allCnt,innerCnt)<<endl;
        //cout<<C[allCnt][innerCnt]<<endl;
    }
    return 0;
}
