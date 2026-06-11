#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  int a,b;
  cin >> a >> b;
  if (a + b < 10){
    cout << a + b << '\n';
  }
  else{
    cout << "error\n";
  }
  return 0;
}