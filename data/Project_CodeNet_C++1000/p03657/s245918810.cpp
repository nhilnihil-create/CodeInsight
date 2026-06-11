#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>

using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  int a,b;
  cin >> a >> b;
  if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0){
    cout << "Possible\n";
  }
  else{
    cout << "Impossible\n";
  }
  return 0;
}