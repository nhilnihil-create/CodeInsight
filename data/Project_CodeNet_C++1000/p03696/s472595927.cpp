#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n; cin >> n;
  string s; cin >> s;
  int l = 0, r = 0;
  rep(i,n){
    if(s[i] == '(') r++;
    else{
      if(r) r--;
      else l++;
    }
  }
  rep(i,l) s = "(" + s;
  rep(i,r) s += ")";
  cout << s;
  cout << "\n";
  return 0;
}
