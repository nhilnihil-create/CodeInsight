#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;
#define top front
int main(){
  int n;
  cin >> n;
  queue<char> c;
  rep(i, n){
    char tmp;
    cin >> tmp;
    c.push(tmp);
  }
  ll ans;
  bool old;
  char k = c.front();
  c.pop();
  if(k == c.front()){
    c.pop();
    ans = 6;
    old = true;
  }else{
    ans = 3;
    old = false;
  }
  while(!c.empty()){
    k = c.top();
    c.pop();
    if(k == c.top()){
      if(old) ans = ans * 3 % MOD;
      else ans = ans * 2 % MOD;
      old = true;
      c.pop();
    }else{
      if(!old) ans = ans * 2 % MOD;
      old = false;
    }
  }
  cout << ans <<endl;
}
    