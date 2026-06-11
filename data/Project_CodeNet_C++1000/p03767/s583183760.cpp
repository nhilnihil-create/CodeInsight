#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n;
  cin >> n;
  vector<ll> a(3*n);
  for(int i=0; i<3*n; ++i) cin >> a[i];
  sort(a.rbegin(), a.rend());

  ll ans = 0;
  for(int i=1; i<n*2; i+=2){
    ans += a[i];
  }

  cout << ans << endl;
}