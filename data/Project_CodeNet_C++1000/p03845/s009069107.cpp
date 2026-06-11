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
  int T[N];
  int ans = 0;
  for(int i=0;i<N;++i) {
    cin>>T[i];
    ans += T[i];
  }
  int M;
  cin>>M;
  int P[M], X[M];
  for(int i=0;i<M;++i) {
    cin>>P[i]>>X[i];
    P[i]--;
  }
  vector<int> arr(M);
  for(int i=0;i<M;++i) {
    cout<<ans-(T[P[i]]-X[i])<<endl;
  }
}

