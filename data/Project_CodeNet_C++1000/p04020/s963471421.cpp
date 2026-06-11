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
  int N;
  cin>>N;
  ll A;
  int num=0;
  ll ans = 0;
  for(int i=0;i<N;++i) {
    cin>>A;
    if(A==0) {
      num = 0;
    }
    else {
      if(num==1) {
        ans += 1;
        A--;
        ans += A/2;
        num = A%2;
      }
      else {
        ans += A/2;
        num = A%2;
      }
    }
  }
  cout<<ans<<endl;
}
