#include <bits/stdc++.h>
#define rep2(i,m,n) for (int i = (int)(m); i < (int)(n); i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;
template <typename T>
T sq(T x){
  return x * x;
}

signed main (){
  ll x;
  cin >> x;
ll cnt= 0;
ll A = x/11;
ll B = x % 11;
ll tot = B;
if(B == 0){
cout << A * 2 << endl;
return 0;

}
  while(tot > 0){
    tot -= 6;
    cnt++;
    if(tot <= 0){
      cout << cnt + A * 2 << endl;
      return 0;
    }
    tot -= 5; 
    cnt++;
    if(tot <= 0){
      cout << cnt  + A * 2<< endl;
      return 0;
    }
  }

  return 0;
}
