#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound

int main(){
  int N,M;
  cin>>N>>M;
  int A[N][M];
  rep(i,N) rep(j,M) cin>>A[i][j];
  int ans=N;
  rep(i,M){
    VI cnt(M);
    rep(j,N){
      rep(k,M){
        if(A[j][k]){
          cnt[A[j][k]-1]++;
          break;
        }
      }
    }
    int tmp=0;
    int tmp2=0;
    rep(j,M){
      if(tmp<cnt[j]){
        tmp=cnt[j];
        tmp2=j;
      }
    }
    rep(j,N) rep(k,M) if(A[j][k]==tmp2+1) A[j][k]=0;
    ans=min(ans,tmp);
  }
  cout<<ans<<endl;
}