#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lb;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define repr(i,j,n) for(ll i = j; i >= (n); i--)
#define each(i,mp) for(auto& i:mp)
#define all(x) (x).begin(),(x).end()
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<b)
#define out(ans) cout << ans << endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef pair<ll,ll>P;
const ll mod=1e9+7;
const ll INF = 1LL<<60;
const ll m=1LL<<32;

int main(){

  ll n;cin>>n;
  string s;cin>>s;
  ll left=0;
  ll right=0;
  string ans="";

  rep(i,0,n){
    if(s[i]=='('){
      left++;
      ans.insert(ans.end(),'(');
    }else{
      ans.insert(ans.end(),')');
      if(left==0)ans.insert(ans.begin(),'(');
      left=max((ll)0,left-1);
    }
  }
  rep(i,0,left)ans.insert(ans.end(),')');
  out(ans);

  return 0;
}
