#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
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
  int N, M, K;
  cin>>N>>M>>K;
  bool can = false;
  for(int i=0;i<=N;++i){
    for(int j=0;j<=M;++j){
      if(i*M+j*N-i*j*2==K) can = true;
    }
  }
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

