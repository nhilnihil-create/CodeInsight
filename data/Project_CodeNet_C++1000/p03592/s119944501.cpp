#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const double PI = acos(-1);  


int main(){
  ll n, m, k; cin >> n >> m >> k;
  string ans="No";
  
  for(int i=0; i<=m; i++){
    for(int j=0; j<=n; j++)
      if((n-j)*i+(m-i)*j==k) ans="Yes";
  }
    
    
  
  cout << ans << endl;  
  
}
