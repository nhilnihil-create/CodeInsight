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

int main() {
  ll N, X;
  cin>>N>>X;
  ll ans = 0;
  ll A[N];
  for(int i=0;i<N;++i) {
    cin>>A[i];
    if(A[i]>X) {
      ans += A[i]-X;
      A[i] = X;
    }
  }
  for(int i=1;i<N;++i) {
    if(A[i-1]+A[i]>X) {
      ans += A[i-1]+A[i]-X;
      A[i] -= A[i-1]+A[i]-X;
    }
  }
  cout<<ans<<endl;
}

