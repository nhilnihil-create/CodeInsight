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
char a,b;
cin >> a >> b;
  bool A_flag , B_flag;
 if((a == 'H'&& b == 'H')||(a == 'D' && b == 'D')){
cout << 'H' << endl;
 }else{
cout << 'D' << endl;
 } 

    return 0;
}
