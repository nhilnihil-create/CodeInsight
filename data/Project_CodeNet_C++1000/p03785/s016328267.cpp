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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N, C, K;
  cin>>N>>C>>K;
  vector<ll> T(N);
  for(int i=0;i<N;++i) cin>>T[i];
  sort(T.begin(), T.end());
  int index = 0;
  int time;
  int num;
  int ans = 0;
  while(true) {
    ans++;
    time = T[index] + K;
    num = 0;
    for(int i=index;i<N;++i) {
      if(T[i]>time || num+1>C) {
        index = i;
        break;
      }
      num++;
      index++;
    }
    if(index==N) break;
  }
  cout<<ans<<endl;
}

