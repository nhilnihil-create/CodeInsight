#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int s_val[100010];
int t_val[100010];

int main(){
  string S,T;
  cin>>S;
  cin>>T;
  int N=S.size();
  int M=T.size();

  s_val[0]=0;
  for(int i=0;i<N;i++){
      int nex=0;
      if(S[i]=='A') nex=1;
      else nex=2;
      s_val[i+1]=(s_val[i]+nex)%3;
  }

  t_val[0]=0;
  for(int i=0;i<M;i++){
      int nex=0;
      if(T[i]=='A') nex=1;
      else nex=2;
      t_val[i+1]=(t_val[i]+nex)%3;
  }

  int Q;
  cin>>Q;
  for(int i=0;i<Q;i++){
      int a,b,c,d;
      cin>>a>>b>>c>>d;

      int s=s_val[b]-s_val[a-1];
      s=(s+3)%3;
      int t=t_val[d]-t_val[c-1];
      t=(t+3)%3;

      if(s==t) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
  }

  return 0;
}
