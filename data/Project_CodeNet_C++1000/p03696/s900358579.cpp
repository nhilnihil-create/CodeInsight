#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  //追加するのは左か右
  int l=0; //左に追加する(
  int r=0; //右に追加する)
  rep(i,s.size()){
    if(s[i]=='('){
      r++;
    }
    if(s[i]==')'){
      if(r>0) r--;
      else l++;
    }
  }
  s.insert(0,string(l,'('));
  s.insert(s.size(),string(r,')'));
  cout << s << endl;
  return 0;
}
