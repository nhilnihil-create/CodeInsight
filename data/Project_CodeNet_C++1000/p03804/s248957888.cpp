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
  int N, M;
  cin>>N>>M;
  vector<string> A(N), B(M);
  for(int i=0;i<N;++i) cin>>A[i];
  for(int i=0;i<M;++i) cin>>B[i];
  bool can = false;
  bool tmpcan;
  for(int i=0;i<=N-M;++i) {
    for(int j=0;j<=N-M;++j) {
      tmpcan = true;
      for(int k=0;k<M;++k) {
        for(int l=0;l<M;++l) {
          if(A[i+k][j+l]!=B[k][l]) tmpcan = false;
        }
      }
      if(tmpcan) can = true;
    }
  }
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

