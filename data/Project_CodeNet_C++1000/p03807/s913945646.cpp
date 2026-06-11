#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  ll a;
  ll eo = 0;
  for (int i = 0; i < n; i++){
    cin >> a;
    if (a % 2){
      eo++;
    }
  }

  if (eo % 2){
    cout << "NO" << endl;
  }
  else
    cout << "YES" << endl;
    

  return 0;
}
