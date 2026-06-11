#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;
#define rep(i,n); for(int i=0;i<n;i++)

int main() {
  string s;
  int k;
  cin >> s >> k;
  int now = k;
  int i=0;
  while(now > 0 && i < s.size()){
    if(s.at(i) == 'a') ;
    else if(26 - (s.at(i)-'a') <= now){
      now -= 26 - (s.at(i) -'a');
      s.at(i) = 'a';
    }
    i++;
  }
  string alpha = "abcdefghijklmnopqrstuvwxyz";
  if(now > 0){
    now %= 26
    rep(i,26){
      if(s.at(s.size()-1) == alpha.at(i)){
        s.at(s.size()-1) = alpha.at(i+now);
        break;
      }
    }
  }
  cout << s << endl;
      
  return 0;
}


