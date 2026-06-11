#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

ll a[100010];

int main(){
  ll n;cin>>n;
  rep(i,n)cin>>a[i];
  ll sum = 0;
  rep(i,n) sum+=a[i];
  ll ral = n*(n+1)/2;
  if(sum%ral!=0) {
    cout<<"NO"<<endl;
    return 0;
  }
  ll num = sum/ral;
  ll cnt=0;
  rep(i,n) {
    ll b = a[(i+1)%n]-a[i]-num;
    if(b%n!=0 || b>0) {
      cout<<"NO"<<endl;
      return 0;
    } else {
      cnt += ((-1)*b)/n;
    }
  }
  if(cnt==num) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
