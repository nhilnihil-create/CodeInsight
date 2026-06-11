#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

ll slime[2005][2005];

int main() {
  ll N, x;
  cin>>N>>x;
  ll a[N];
  for(int i=0;i<N;++i){
    cin>>a[i];
  }
  for(int i=0;i<N;++i){
    slime[i][0] = a[i];
  }
  for(int i=0;i<N;++i){
    for(int j=1;j<N;++j){
      slime[i][j] = min(slime[i][j-1], a[(i-j+N)%N]);
    }
  }
  ll ans = 0;
  for(int i=0;i<N;++i) ans += a[i];
  ll tmpans;
  for(int j=1;j<N;++j){
    tmpans = x*j;
    for(int i=0;i<N;++i){
      tmpans += slime[i][j];
    }
    ans = min(ans, tmpans);
  }
  cout<<ans<<endl;
}
