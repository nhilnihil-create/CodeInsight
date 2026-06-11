#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  string s;
  cin >> s;
  ll ans = s.length() / 2;

  rep(i, s.length()) {
    if(s[i] == 'p') --ans;
  }
  cout << ans << endl;
}