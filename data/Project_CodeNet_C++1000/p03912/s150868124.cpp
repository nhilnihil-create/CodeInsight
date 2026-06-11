#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;


//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    map<int,int> mp;
    VI x(n);
    map<int,int> tmp;
    map<int,int> pairCnt;
    rep(i,n){
      cin >> x[i];
      if(tmp[x[i]] > 0){
        tmp[x[i]]--;
        pairCnt[x[i]%m]++;
      }else {
        tmp[x[i]]++;
      }
      mp[x[i] % m]++;
    }


    ll ans = 0;
    rep(i,m){
      int x;
      if(i != (m-i)%m) x = min(mp[i] , mp[(m-i)%m]);
      else x = mp[i]/2;
      mp[i] -= x;
      mp[(m-i)%m] -= x;
      ans += x;
    }

    //cout << "ans" << ' ' << ans << "\n";
    rep(i,m){
      //cout << i << ':' << pairCnt[i] << "\n";
      if(pairCnt[i] > 0 && mp[i] > 0){
        ans += min(mp[i]/2,pairCnt[i]);
      }
    }

    cout << ans << endl;
    return 0;
}
