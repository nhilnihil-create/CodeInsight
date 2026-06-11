#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long

using namespace std;
using P = pair<int,int>;

int main(){

  string S;
  cin >> S;
  S.erase(S.size()-1);
  int n = S.size();
  int ans = 0;

  for (int i = 0; i < n; i++) {

    int num = S.size();
    if(num % 2 == 0){
      string a = S.substr(0,num/2);
      string b = S.substr(num/2,num/2);
      if(a == b){
        cout << num << endl;
        return 0;
      }
    }
    S = S.erase(num-1); // 1文字削除
  }

  return 0;
}