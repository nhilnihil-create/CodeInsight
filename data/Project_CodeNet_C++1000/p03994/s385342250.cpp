#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int MAX = 1000000;
const ll INF = (1LL << 31) - 1;
const double pi=acos(-1);

int main(){
  string s;
  ll K;
  cin >> s >> K;
  int n = s.size();
  rep(i,n){
    if(s[i]=='a')continue;
    else{
      int num = s[i]-'a';
      if(26-num<=K){
        K-=26-num;
        s[i]='a';
      }
    }
  }
  K%=26;
  int res = (s[n-1]-'a'+K)%26;
  s[n-1]=char('a'+res);
  cout << s << endl;
}
