#include<bits/stdc++.h>
#define rep(i,n)  for(ll i=0; i<n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF 1e9
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
  ll q,h,s,d,n; cin >> q >> h >> s >> d >> n;
  chmin(h,q*2);
  chmin(s,h*2);
  cout << (s*2<d ? n*s : (n/2)*d+(n%2)*s);
  cout << "\n";
  return 0;
}
