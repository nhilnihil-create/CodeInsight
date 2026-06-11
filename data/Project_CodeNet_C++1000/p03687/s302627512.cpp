#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  string s;
  cin >> s;
  int res = 1 << 30;
  for(char c = 'a';c <= 'z';c++){
    string t = s;
    int cnt = 0;
    while(t != string(t.length(),c)){
      string u = "";
      cnt++;
      for(int i = 0;i < t.size()-1;i++){
        if(t[i] == c || t[i+1] == c)u += c;
        else u += t[i];
      }
      t = u;
    }
    res = min(res,cnt);
  }
  cout << res << endl;

  





  return 0;
}