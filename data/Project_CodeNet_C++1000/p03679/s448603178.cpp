#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int x,a,b;cin>>x>>a>>b;
  if(a>=b) cout << "delicious" << endl;
  else if(a<b&&b-a>=x+1) cout << "dangerous" << endl;
  else cout << "safe" << endl;
}