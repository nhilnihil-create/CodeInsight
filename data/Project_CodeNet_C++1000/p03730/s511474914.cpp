#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = (ll) 1e18;
int main()
{
  ll a,b,c;
  cin >> a >> b >> c;
  for(int i=0;i<b;i++){
    if((a*i)%b==c){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}