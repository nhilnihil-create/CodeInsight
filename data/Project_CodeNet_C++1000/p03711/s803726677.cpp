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
  int x,y;
  cin >> x >> y;
  int ans_x,ans_y;
  vector<int> A{1,3,5,7,8,10,12};
  vector<int> B{4,6,9,11};
  vector<int> C{2};
  rep(i,7){
    if(A.at(i) == x)ans_x = 0;
    if(A.at(i) == y)ans_y = 0;
  }
  rep(i,4){
    if(B.at(i) == x)ans_x = 1;
    if(B.at(i) == y)ans_y = 1;

  }
  if(C.at(0) == x )ans_x = 2;
  if(C.at(0) == y )ans_y = 2;

 if(ans_x == ans_y){
   cout << "Yes" <<endl;
    return 0;
  }else{
    cout << "No" <<endl;
  }
  return 0;
}
