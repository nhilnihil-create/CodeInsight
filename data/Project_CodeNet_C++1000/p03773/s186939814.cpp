#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int a,b;
  cin >> a >> b;
  if( a+b >23 ){
    cout << a+b-24 << endl;
  }else{
    cout << a+b << endl;
  }
  return 0;
}