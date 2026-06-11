#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=2e9;
const ll lnf=9e18;

int main(){
  itn n,x; cin >> n >> x;
  x--;
  if(x==0||x==2*n-2){
    cout << "No" << endl;
    return 0;
  }
  vector<itn> ans(2*n-1);
  rep(i,2*n-1){
    ans[i]=i;
  }
  if(x==n-1){
    cout << "Yes" << endl;
    rep(i,ans.size()) cout << ans[i]+1 << endl;
    return 0;
  }
  else if(x<n-1){
    swap(ans[0],ans[n-1]);
    swap(ans[x],ans[n]);
  }
  else{
    swap(ans[2*n-2],ans[n-1]);
    swap(ans[x],ans[n-2]);
  }
  cout << "Yes" << endl;
  rep(i,ans.size()) cout << ans[i]+1 << endl;
}