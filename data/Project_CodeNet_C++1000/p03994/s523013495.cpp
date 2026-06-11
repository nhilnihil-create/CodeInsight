#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

int main(){
  string s;
  cin>>s;
  int k;
  cin>>k;
  int N = int(s.size());
  int sum(0);
  for(int i(0);i<N;i++){
    if(s[i] == 'a') continue;
    sum += 26 - (s[i]-'a');
  }
  if(sum > k){
    for(int i(0);i<N;i++){
      if(s[i]=='a') continue;
      int tmp = 26 - (s[i]-'a');
      //cout << tmp << endl;
      if(k >= tmp){
        k -= tmp;
        s[i] = 'a';
      }
    }
    s[N-1] = (char)(s[N-1] + k);
  }else{
    string ans(N,'a');
    int amari = k-sum;
    amari %= 26;
    ans[N-1] = (char)('a'+amari);
    s = ans;
  }
  cout << s << endl;
  return 0;
}
