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
  string s;
  cin >> s;
  if (s[0] == '9' || s[1] == '9'){
    cout << "Yes\n";
  }
  else{
    cout << "No\n";
  }
  return 0;
}