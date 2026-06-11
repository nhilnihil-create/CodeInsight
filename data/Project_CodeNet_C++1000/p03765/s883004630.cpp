#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S,T;
  cin>>S>>T;
  ll n = S.size(),m=T.size();
  vector<int> v(n+1,0),u(m+1,0);
  rep(i,n){
    int t = S[i] - 'A';
    t++;
    v[i+1] = v[i] + t; 
  }
  rep(i,m){
    int t = T[i] - 'A';
    t++;
    u[i+1] = u[i] + t;
  }
  ll q;
  cin>>q;
  rep(i,q){
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    int s = (v[B]-v[A-1])%3;
    if(s<0) s+=3;
    int t = (u[D]-u[C-1])%3;
    if(t<0) t += 3;
    if(s==t) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}