#include<bits/stdc++.h>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef long long ll;
typedef pair<ll,ll> P;
const int INF=INT_MAX / 3;
const ll LINF=LLONG_MAX / 3LL;
#define CONST 1000000007
#define EPS (1e-8)
#define PB push_back
#define MP make_pair
#define sz(a) ((int)(a).size())
#define reps(i,n,m) for(int i=(n);i<int(m);i++)
#define rep(i,n) reps(i,0,n)
#define SORT(a) sort((a).begin(),(a).end())
ll mod(ll a,ll m){return (a%m+m)%m;}
int dx[9]={0,1,0,-1,1,1,-1,-1,0},dy[9]={1,0,-1,0,1,-1,1,-1,0};
ll n,m;
int pir[200000];
int md[200000];
int main(){
  vector<int> vec;
  int ans=0;
  cin>>n>>m;
  rep(i,n) {
    int x;
    cin>>x;
    vec.PB(x);
  }
  SORT(vec);
  rep(i,n){
    md[vec[i]%m]++;
    if(i+1<n&&vec[i]==vec[i+1]){
      md[vec[i]%m]++;
      pir[vec[i]%m]++;
      i+=1;
    }
  }

  rep(i,m){
    cerr<<" "<<md[i];
  }
  cerr<<endl;
  rep(i,m){
    cerr<<" "<<pir[i];
  }
  cerr<<endl;

  ans += md[0]/2;
  reps(i,1,(m+1)/2){
    int l = (md[i] < md[m-i]) ? i : m-i;
    int r = (md[i] < md[m-i]) ? m-i : i;
    cerr<<"!"<<i<<" "<< md[l] + min((md[r]-md[l])/2, pir[r])<<endl;;
    ans += md[l] + min((md[r]-md[l])/2, pir[r]);
  }
  if(m%2==0) {
    ans += md[m/2]/2;
  }
  cout<<ans<<endl;
  return 0;
}
