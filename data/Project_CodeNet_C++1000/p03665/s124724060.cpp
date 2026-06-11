# include <iostream>
# include <map>
# include <algorithm>
using namespace std;

# define ll long long

int main(){
  
  bool allNumbersEven = true;
  int n, p;
  cin >> n >> p;
  
  for(int i=0; i<n; i++){
    int num;
    cin >> num;
    if(num % 2 == 1) allNumbersEven = false;
  }
  
  ll ans;
  if(allNumbersEven){
    if(p == 0) ans = 1ll << n;
    else ans = 0;
  } else {
    ans = 1ll << (n-1);
  }
  
  cout << ans << endl;
  return 0;
} 

