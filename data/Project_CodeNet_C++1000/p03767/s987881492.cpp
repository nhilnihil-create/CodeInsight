# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;
# define ll long long

int main(){
  int n;
  cin >> n;
  ll ans = 0;
  vector<int> num(n*3);
  for(int i=0; i<n*3; i++) cin >> num[i];
  sort(num.rbegin(), num.rend());
  
  for(int i=1; i<2*n; i+=2) ans += num[i];
  cout << ans << endl;
  return 0;
}