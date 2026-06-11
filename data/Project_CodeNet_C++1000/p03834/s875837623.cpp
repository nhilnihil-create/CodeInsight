#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  string s;
  cin >> s;
  rep(i,19){
    if(i==5||i==13){
      cout << " ";
    }
    else{
      cout << s[i];
    }
  }

  
}
      