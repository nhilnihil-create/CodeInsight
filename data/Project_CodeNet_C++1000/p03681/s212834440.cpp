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
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

ll frac[100005];

int main() {
  frac[0] = 1;
  for(ll i=1;i<100005;++i) frac[i] = frac[i-1]*i%mod;
  ll N, M;
  cin>>N>>M;
  if(N==M) {
    cout<<frac[N]*frac[M]%mod*2%mod<<endl;
  }
  else if(abs(N-M)==1) {
    cout<<frac[N]*frac[M]%mod<<endl;
  }
  else {
    cout<<0<<endl;
  }
}

