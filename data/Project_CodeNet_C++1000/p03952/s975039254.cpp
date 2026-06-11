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
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;
  
int main() {
  int N,x;
  cin >> N >> x;
  if(N==x) {
    cout << "Yes" << endl;
    rep(i,2*N-1) {
      cout << i+1 << endl;
    }
    return 0;
  }
  if(x==1||x>=2*N-1) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  int k = 2;
  rep(i,N-2) {
    if(k==x) k++;
    cout << k << endl;
    k++;
  }
  if(x==2*N-2) {
    cout << 1 << endl;
    cout << 2*N-1 << endl;
    cout << x << endl;
    cout << k << endl;
    k++;
  } else {
    cout << 2*N-1 << endl;
    cout << 1 << endl;
    cout << x << endl;
    cout << 2*N-2 << endl;
  }
  rep(i,N-3) {
    if(k==x) k++;
    cout << k << endl;
    k++;
  }
  return 0;
}