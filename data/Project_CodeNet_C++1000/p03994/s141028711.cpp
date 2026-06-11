#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  string s;ll k;
  cin >> s >> k;
  rep(i,s.size()){
    if(k == 0)break;
    if(s[i] == 'a')continue;
    else {
      if(('z'-s[i]+1) > k)continue;
      k -= ('z'-s[i]+1);
      s[i] = 'a';
    }
  }
  if(k > 0){
    k %= 26;
    s.back() = (s.back()-'a'+k)%26+'a';
  }
  cout << s << endl;
  





  return 0;
}