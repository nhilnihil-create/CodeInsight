#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  string s;
  cin >> s;

  ll n = s.size();

  if(((s[0] == s[n - 1]) && (n % 2 == 0)) || ((s[0] != s[n - 1]) && (n % 2 == 1))){
    cout << "First" << endl;
  } else{
    cout << "Second" << endl;
  }
  
  return 0;
}