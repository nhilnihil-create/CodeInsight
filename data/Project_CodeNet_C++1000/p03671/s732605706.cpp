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
 vector<int> a(3);
 rep(i,3){
 cin >> a.at(i);
 }
sort(all(a));
cout << a.at(0) + a.at(1) << endl;
    return 0;
}
