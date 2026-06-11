#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  ll a,b,c;
  cin >> a >> b >> c;
  if(a*b*c%2==0){
    cout << 0 << endl;
    return 0;
  }
  vector<ll> vec(3);
  vec[0]=a;vec[1]=b;vec[2]=c;
  sort(vec.begin(),vec.end());
  cout << vec[0]*vec[1] << endl;
}