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
  ll N, L;
  cin>>N>>L;
  ll A[N];
  for(int i=0;i<N;++i) cin>>A[i];
  int index;
  bool can = false;
  for(int i=0;i<N-1;++i) {
    if(A[i]+A[i+1]>=L) {
      index = i+1;
      can = true;
      break;
    }
  }
  if(!can) {
    cout<<"Impossible"<<endl;
    return 0;
  }
  cout<<"Possible"<<endl;
  for(int i=1;i<index;++i) cout<<i<<endl;
  for(int i=N-1;i>=index;--i) cout<<i<<endl;
}

