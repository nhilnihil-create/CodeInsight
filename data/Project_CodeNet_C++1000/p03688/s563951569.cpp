#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define pb push_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
typedef long long ll;
typedef multiset<ll> S;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,vector<ll>,greater<ll>> SPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
bool chmin(auto &a,auto b){if(a>b){a=b;return true;}return false;}
bool chmax(auto &a,auto b){if(a<b){a=b;return true;}return false;}

int main(){
    int n;cin>>n;
   vi v(n);
  rep(i,n)cin>>v[i];
  sort(all(v));
  ll a=0,b=0;
  rep(i,n){
    if(v[i]==v[0])a++;
    else if(v[i]==v[0]+1)b++;
    else {
      cout<<"No"<<endl;
      return 0;
    }
  }
  int m=-1;
  if(v[0]!=v[n-1])m++;
    if((v[0]+1-a)*2<=b&&m<v[0]+1-a){
      cout<<"Yes"<<endl;
      return 0;
    }
    if(v[0]==v[n-1]){
      if((v[0]-b)*2<=a&&m<v[0]-b){
        cout<<"Yes"<<endl;
        return 0;
      }
      }
      cout<<"No"<<endl;
}
