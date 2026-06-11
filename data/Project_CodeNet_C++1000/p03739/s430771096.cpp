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
  int N;
  cin>>N;
  ll A[N];
  for(int i=0;i<N;++i) cin>>A[i];
  ll ans1=0, ans2=0, sum;
  sum = 0;
  for(int i=0;i<N;++i) {
    sum += A[i];
    if(i%2==0) { // 0, 2, 4..を正
      if(sum<=0) {
        ans1 += 1-sum;
        sum = 1;
      }
    }
    else {
      if(sum>=0) {
        ans1 += sum+1;
        sum = -1;
      }
    }
  }
  sum = 0;
  for(int i=0;i<N;++i) {
    sum += A[i];
    if(i%2==0) { // 0, 2, 4..を負
      if(sum>=0) {
        ans2 += sum+1;
        sum = -1;
      }
    }
    else {
      if(sum<=0) {
        ans2 += 1-sum;
        sum = 1;
      }
    }
  }
  cout<<min(ans1, ans2)<<endl;
}

