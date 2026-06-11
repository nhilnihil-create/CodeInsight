#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MOD = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 100100;

int H,W,h,w;
int G[MAXN];

int main(){
  cin>>H>>W>>h>>w;
  if (H%h==0&&W%w==0){
    cout<<"No\n";
    return 0;
  }
  int extras = (H%h*W) + (W%w*H) - (H%h)*(W%w);
  // cout<<extras<<'\n';

  int losses = (H/h)*(W/w);
  // cout<<losses<<' '<<extras<<'\n';
  int m = (losses + extras)/extras;
  cout<<"Yes\n";
  for (int i=1;i<=H;++i){
    for (int j=1;j<=W;++j){
      if (i%h==0&&j%w==0){
        cout<<-(h*w-1)*m - 1<<' ';
      }else{
        cout<<m<<' ';
      }
    }
    cout<<'\n';
  }

}
