#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

vvi d;
vi r;
int R,ans=INF;
vb used;

void dfs(int sum,int last,int num) {
  if(num==R) {
    ans=min(ans,sum);
    return;
  }
  rep(i,R) {
    if(used[i]) continue;
    used[i]=true;
    if(last==-1) dfs(0,i,1);
    else dfs(sum+d[r[last]][r[i]],i,num+1);
    used[i]=false;
  }
}

int main() {
  int N,M;
  cin >> N >> M >> R;
  r=vi(R);
  rep(i,R) {
    cin >> r[i];
    r[i]--;
  }
  vi A(M),B(M),C(M);
  d=vvi(N,vi(N,INF));
  rep(i,N) d[i][i]=0;
  rep(i,M) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--;B[i]--;
    d[A[i]][B[i]]=C[i];
    d[B[i]][A[i]]=C[i];
  }
  
  rep(i,N) {
    rep(j,N-1) {
      rep2(k,j+1,N) {
        d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
        d[k][j]=min(d[j][k],d[j][i]+d[i][k]);
      }
    }
  }
  
  used=vb(R);
  dfs(0,-1,0);
  
  cout << ans << endl;
}