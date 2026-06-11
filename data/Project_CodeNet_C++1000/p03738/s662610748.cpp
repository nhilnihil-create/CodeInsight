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
  string a, b;
  cin >> a >> b;
  bool flag;

  if (a==b){
    print("EQUAL");
    return 0;
  }

  if(a.size() > b.size()){
    flag = true;
  } else if (a.size() < b.size()){
    flag = false;
  } else {
    rep(i, a.size()){
      if(a[i] == b[i]) continue;
      else if(int(a[i]) < int(b[i])){
        flag = false;
        break;
      } else {
        flag = true;
        break;
      }
    }
  }

  if(flag){
    print("GREATER");
  } else {
    print("LESS");
  }
}
