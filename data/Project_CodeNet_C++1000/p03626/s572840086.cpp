#include <bits/stdc++.h>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i,a,b) for (ll i=(a);i<(ll)b; i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define INF 1LL << 60
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll,ll> p;
const long long MOD=1000000007;

// vector<p> cut(M);
// cut[i].second
// cut[i].first;
// REP(i,M){
//     int a,b;cin>>a>>b;
//     cut[i] = make_pair(b,a);//last first の順番
// }
// for(int i=0; i<N;i++){
// }
// sort(cut.begin(),cut.end()); //sort
// char '' str ""
int main(void)
{
    int N; str S, SS;cin>>N>>S>>SS;
    ll ans=1;
    int flag=0;
    for(int i=0; i<N;i++){
      char s = S[i]; char ss = SS[i];
      // cout<<i<<" ";
      if(i==0){
        if(s!=ss){ans*=6LL; flag=0; i++;}
        else{ans *= 3LL; flag=1;}
      }else{
        if(s!=ss){
          if(flag==0) ans*= 3LL;
          if(flag==1) ans*= 2LL;
          flag=0; i++;
        }else{
          if(flag==0) ans*= 1LL;
          if(flag==1) ans*= 2LL;
          flag=1;
        }
      }
      ans %= MOD;
      // cout<<i<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
