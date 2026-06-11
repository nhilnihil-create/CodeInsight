#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 1000000007

int N;
int A[200010],B[200010];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>N;
  rep(i,2*N-1)cin>>A[i];

  int lb=1,ub=2*N;
  while(ub-lb>1){
    int X=(lb+ub)/2;
    rep(i,2*N-1){
      if(A[i]>=X)B[i]=1;
      else B[i]=0;
    }
    int cent=B[N-1],nxt=1-B[N-1];
    int top=-1;
    repl(i,1,N){
      if(nxt!=B[N-1-i]||nxt!=B[N-1+i]){
        top=1-nxt; break;
      }
      nxt=1-nxt;
    }
    if((top==-1&&cent%2==N%2)||top==1)lb=X;
    else ub=X;
  }
  cout<<lb<<endl;

  return 0;
}
