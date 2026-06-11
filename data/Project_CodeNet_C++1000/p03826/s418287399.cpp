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
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  if(A * B >= C *D){
cout << A * B << endl;
 return 0;
  }else{
cout << C * D  << endl;
return 0;
  }

    return 0;
}
