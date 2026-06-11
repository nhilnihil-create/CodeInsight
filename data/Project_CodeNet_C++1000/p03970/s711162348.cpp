#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,k,a[10];
string s,t;

int main() {
  cin >> s;
  t="CODEFESTIVAL2016";
  int cnt=0;
  rep(i,s.size()){
    if(s[i]!=t[i]) cnt++;
  }
  cout << cnt << endl;
}