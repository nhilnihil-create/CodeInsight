#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll q,h,s,d;
  cin >> q >> h >> s >> d;
  ll n;
  cin >> n;
  vector<ll> vec={q*4,h*2,s};
  sort(vec.begin(), vec.end());
  ll one=vec.at(0);
  if(one*2<d || n==1)
    cout << one*n << endl;
  else{
    if(n%2==0)
      cout << d*n/2 << endl;
    else
      cout << d*(n-1)/2+one << endl;
  }
}
