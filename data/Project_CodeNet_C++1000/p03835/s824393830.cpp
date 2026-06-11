#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
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
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int K, S;
  cin>>K>>S;
  int ans = 0;
  for(int X=0;X<=K;++X) {
    for(int Y=0;Y<=K;++Y) {
      if(0<=S-X-Y && S-X-Y<=K) ans++;
    }
  }
  cout<<ans<<endl;
}

