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
  ll a,b,c; cin >> a >> b >> c;
  set<int> st;
  for(int i = 0; st.count((a*i)%b) == 0; i++){
    st.insert((a*i)%b);
  }
  if(st.count(c)) cout << "YES";
  else cout << "NO";
  cout << "\n";
  return 0;
}
