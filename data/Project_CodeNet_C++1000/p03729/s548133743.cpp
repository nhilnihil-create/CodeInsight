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
  string A,B,C;
  cin >> A >> B >> C;
  if(A.at(A.size() - 1) == B.at(0) && B.at(SZ(B)-1) == C.at(0)){
cout << "YES" << endl;
return 0;
  }else{
cout << "NO" <<endl;
  }
    return 0;
}
