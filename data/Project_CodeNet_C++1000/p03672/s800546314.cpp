#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define prints(x, y) cout<<(x)<<" "<<(y)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  string s;
  cin >> s;
  bool flag;

  for(int i = s.size()-2; i >= 0; i-=2){
    flag = true;
    for(int j = 0; j < i/2; j++){
      if(s[j] != s[i/2+j]) {
        flag = false;
        break;
      }
    }
    if(flag) {
      print(i);
      return 0;
    }
  }
  print(1);
}
