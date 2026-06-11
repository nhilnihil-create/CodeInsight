#ifdef __LOCAL
  #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
#define intmax numeric_limits<int>::max()
#define llmax numeric_limits<ll>::max()
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
const int inf=1<<30;
const ll lnf=1ll<<60;

itn cnt1[100010];
itn cnt2[100010];
itn scnt1[100010];
itn scnt2[100010];

int main(){
  string ss,tt; cin >> ss >> tt;
  rep(i,ss.size()){
    if(ss[i]=='A') cnt1[i]++;
    else cnt1[i]+=2;
  }
  rep(i,ss.size()) scnt1[i+1]=scnt1[i]+cnt1[i];
  rep(i,tt.size()){
    if(tt[i]=='A') cnt2[i]++;
    else cnt2[i]+=2;
  }
  rep(i,tt.size()) scnt2[i+1]=scnt2[i]+cnt2[i];
  vector<string> ans;
  ll T; cin >> T;
  while(T--){
    itn a,b,c,d;
    cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    if((scnt1[b+1]-scnt1[a])%3==(scnt2[d+1]-scnt2[c])%3) ans.push_back("YES");
    else ans.push_back("NO");
  }
  for(auto v:ans) cout << v << endl;
}