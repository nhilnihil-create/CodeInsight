#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <set>
#include <math.h>
#define pai 3.14159265358979323846264338327950288;
#define keta(n) cout << fixed << setprecision((n));
using ll = long long;
int main()
{
  string s;
  cin>>s;
  string ans ;
  for(int i=0;i<s.size();i += 2){
    ans += s[i];
  }
  cout<<ans<<endl;
}
