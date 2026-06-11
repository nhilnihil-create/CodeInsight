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

int N;
vector<ll> X;
ll L;
int Q;

int nxt[20][100010];
const ll INF = 1e15;

int main(){
  cin>>N;
  X.resize(N);
  rep(i,N) cin>>X[i];
  cin>>L;

  X.push_back(INF);
  for(int i=0;i<N;i++) for(int j=0;j<20;j++) nxt[j][i]=-1;
  for(int i=0;i<N;i++){
      int z=upper_bound(X.begin(),X.end(),X[i]+L)-X.begin();
      z--;
      nxt[0][i]=z;
  }
  nxt[0][N-1]=-1;
  for(int k=0;k+1<20;k++){
      for(int i=0;i<N;i++){
          if(nxt[k][i]==-1) continue;
          nxt[k+1][i]=nxt[k][nxt[k][i]];
      }
  }

  cin>>Q;
  vector<int> ans(Q,0);
  for(int q=0;q<Q;q++){
      int a,b;
      cin>>a>>b;
      a--;
      b--;

      if(a>b) swap(a,b);

      int ok=N,ng=0;
      while(ok-ng>1){
          int mid=(ok+ng)/2;
          int now=a;
          for(int k=0;k<20;k++){
              if(mid&(1<<k)){
                  now=nxt[k][now];
                  if(now==-1) break;
              }
          }

          if(now>=b||now==-1) ok=mid;
          else ng=mid;
      }
      ans[q]=ok;
  }

  for(int i=0;i<Q;i++) cout<<ans[i]<<endl;
  

  return 0;
}
