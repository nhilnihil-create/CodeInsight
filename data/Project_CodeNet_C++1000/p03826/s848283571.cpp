#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std;

int main() {
  
  int a,b,c,d;
  string s;
  long long ans = 0;
  
  cin >> a >> b >> c >> d;

  if(a*b > c*d) ans = a*b;
  else ans = c*d;
  cout << ans << endl;

}