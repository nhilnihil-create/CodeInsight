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
  string S;
  cin >> S;
vector<int> cnt(27);

rep(i,SZ(S)){
cnt.at(int(S.at(i)) - int('a'))++;
}
rep(i,27){

if(cnt.at(i) > 1){
cout << "no" << endl;
return 0;
}
}

cout << "yes" << endl;
    return 0;
}
