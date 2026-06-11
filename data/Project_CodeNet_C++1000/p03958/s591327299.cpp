#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

// |o|o||||  |...最多種 o...その他（|の間にoを入れ込むイメージ）

int main(){
  int K,T; cin >> K >> T;
  int a[T]; REP(i,T){cin >> a[i];}
  sort(a,a+T,greater<int>());
  int most = a[0];
  int rest = K-most;
  if(rest>=most-1){
    cout << "0\n";
  }else{
    cout << most-rest-1 << "\n";
  }
  
}