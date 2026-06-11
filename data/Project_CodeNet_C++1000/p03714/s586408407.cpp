#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

int main(){
  int n;
  cin >> n;
  vl a(3*n);
  rep(i,3*n) cin >> a.at(i);
  priority_queue<long, vl, greater<long>> que1;
  priority_queue<long> que2;
  vl l(n+1);
  vl r(n+1);
  rep(i,n){
    l.at(0) += a.at(i);
    que1.push(a.at(i));
  }
  rep(i,n){
    if(que1.top() < a.at(n+i)){
      l.at(i+1) = l.at(i) - que1.top() + a.at(n+i);
      que1.pop();
      que1.push(a.at(n+i));
    }else{
      l.at(i+1) = l.at(i);
    }
  }
  reverse(all(a));
  rep(i,n){
    r.at(0) += a.at(i);
    que2.push(a.at(i));
  }
  rep(i,n){
    if(que2.top() > a.at(n+i)){
      r.at(i+1) = r.at(i) - que2.top() + a.at(n+i);
      que2.pop();
      que2.push(a.at(n+i));
    }else{
      r.at(i+1) = r.at(i);
    }
  }
  long ans = l.at(0) - r.at(n);
  rep(i,n){
    ans = max(ans, l.at(i+1) - r.at(n-i-1));
  }
  cout << ans << endl;
}