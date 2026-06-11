#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
#define rep(i,a,b) for(ll i=a ; i<b ; i++)
#define qrep(que, ite) for(auto ite=begin(que) ; ite!=end(que) ; ite++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1LL<<60;
const int inf = 1e5;
//typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ll mo = 998244353;
ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; }
int main(){
  int k,t;  cin >> k >> t;
  vector<int> v(t);
  rep(i,0,t){
    cin >> v[i];
  }
  priority_queue<pii> que;
  rep(i,0,t){
    que.push(mp(v[i],i));
  }
  int cnt=0;
  int pre = -1;
  while(que.size()){
    pii x=que.top();  que.pop();
    if(!que.size()){
      if(x.se==pre) cnt++;
      else pre=x.se;
      if(x.fi-1!=0) que.push(mp(x.fi-1, x.se));
    }else{
      if(x.se==pre){
        pii y=que.top();  que.pop();
        pre=y.se;
        if(y.fi-1!=0) que.push(mp(y.fi-1, y.se));
        que.push(mp(x.fi, x.se));
      }else{
        pre=x.se;
        if(x.fi-1!=0) que.push(mp(x.fi-1, x.se));
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
