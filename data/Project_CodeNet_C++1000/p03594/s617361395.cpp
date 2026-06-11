#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define R cin>>
#define Z class
#define ll long long
#define ln cout<<'\n'
#define in(a) insert(a)
#define pb(a) push_back(a)
#define pd(a) printf("%.10f\n",a)
#define mem(a) memset(a,0,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define iter(c) __typeof((c).begin())
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
template<Z A>void pr(A a){cout<<a;ln;}
template<Z A,Z B>void pr(A a,B b){cout<<a<<' ';pr(b);}
template<Z A,Z B,Z C>void pr(A a,B b,C c){cout<<a<<' ';pr(b,c);}
template<Z A,Z B,Z C,Z D>void pr(A a,B b,C c,D d){cout<<a<<' ';pr(b,c,d);}
template<Z A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}
ll check(ll n,ll m,ll x,ll y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1000000007,MAXL=1LL<<61,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<int,int> P;

void Main() {
  ll n,m,d;
  cin >> n >> m >> d;
  string s="RYGB";
  char c[n][m];
  rep(i,n)rep(j,m) c[i][j]='*';
  if(d%2) {
    rep(i,n) {
      rep(j,m) c[i][j]=s[(i+j)%2];
    }
    rep(i,n) {rep(j,m) cout << c[i][j];ln;}
    return;
  }
  bool f=1;
  int k=0,kk=0,k2=0,xx=0,yy=0;
  for(int i=0; i<n; i++) {
    int l=k/2,ff=0,x=xx,y=yy;
    for(int j=0; j<m; j++) {
      rep(t,2) {
        if(!ff) {
          if(l>=k) {
            l=0;
            ff=1;
            x=(x+1)%2;
          }
        } else {
          if(l>=d-k) {
            l=0;
            ff=0;
            y=(y+1)%2;
          }
        }
      }
      if(ff) c[i][j]=s[x];
      else c[i][j]=s[y+2];
      l++;
    }
    if(f) k+=2;
    else k-=2;
    if(k<0) {
      k+=4;
      f=1;
      kk++;
      yy=(yy+1)%2;
    } else if(k>d) {
      k-=4;
      f=0;
      k2++;
      xx=(xx+1)%2;
    }
  }
  rep(i,n) {
    rep(j,m) cout << c[i][j];
    ln;
  }
}

int main(){ios::sync_with_stdio(0);cin.tie(0);Main();return 0;}
