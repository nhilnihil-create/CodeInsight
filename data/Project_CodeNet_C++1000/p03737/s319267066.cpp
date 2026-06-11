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
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  
  cout << (char)(s1[0] - 32);
  cout << (char)(s2[0] - 32);
  cout << (char)(s3[0] - 32) << endl;
  
  return 0;
}