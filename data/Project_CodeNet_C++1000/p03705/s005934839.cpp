# include <iostream>
# include <map>
# include <algorithm>
using namespace std;

# define ll long long

int main(){
  
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans = 0;
  
  if(a > b) ans = 0;
  else if(n == 1) ans = (a==b);
  else {
    ll min = b + (n-1)*a;
    ll max = a + (n-1)*b;
    ans = max - min + 1;
  }
  
  cout << ans << endl;
  
  return 0;
} 