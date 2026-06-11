# include <iostream>
using namespace std;
# define ll long long

int main(){
  ll n; int p;
  cin >> n >> p; 

  bool allEven = true;
  for(int i=0; i<n; i++){
    ll num;
    cin >> num;
    if(num % 2 == 1) allEven = false;
  }

  if(allEven) cout << (p ? 0 : (1ll<<n)) << endl;
  else cout << (1ll<<(n-1)) << endl;
  return 0;
}