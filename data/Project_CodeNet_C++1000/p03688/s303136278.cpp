#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef pair<double,double> PD;
typedef pair<int,P> ed;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;
  
int main() {
  int N;
  cin >> N;
  vi A(N);
  int maxa=0,mina=INF;
  rep(i,N) {
    cin >> A[i];
    chmax(maxa,A[i]);
    chmin(mina,A[i]);
  }
  if(maxa-mina>1) {
    cout << "No" << endl;
    return 0;
  }
  if(maxa-mina) {
    int uniq=0;
    rep(i,N) {
      if(A[i]==mina) uniq++;
    }
    int maxkind = uniq+(N-uniq)/2;
    int minkind = uniq+1;
    if(minkind>maxa||maxkind<maxa) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
    return 0;
  }
  if(maxa==N-1) {
    cout << "Yes" << endl;
    return 0;
  }
  int minkind=1;
  int maxkind=N/2;
  if(minkind>maxa||maxkind<maxa) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}