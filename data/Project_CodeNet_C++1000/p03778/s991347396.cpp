#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)


int main() {
  int a,b,c;
  cin>>a>>b>>c;
  cout<<max(0,abs(b-c)-a)<<endl;
}
