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

bool D[10];

int main() {
  int N, K;
  cin>>N>>K;
  int tmp;
  for(int i=0;i<K;++i) {
    cin>>tmp;
    D[tmp] = true;
  }
  int ans;
  string tmpans;
  bool can;
  for(int i=N;i<1000000;++i) {
    tmpans = to_string(i);
    can = true;
    for(int j=0;j<tmpans.size();++j) {
      if(D[tmpans[j]-'0']) can = false;
    }
    if(can) {
      ans = i;
      break;
    }
  }
  cout<<ans<<endl;
}

