#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  string a,b,c;
  int i,j;
  cin >> a >> b >> c;
  i = a.size();
  j = b.size();
  if (a[i-1] == b[0] && b[j-1] == c[0]){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }
  return 0;
} 