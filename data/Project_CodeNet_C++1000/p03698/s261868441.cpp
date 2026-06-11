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
  vector<int> a(26, 0);

  for(char c: s){
    a[c-'a']++;
  }

  rep(i, 26){
    if(a[i] > 1){
      print("no");
      return 0;
    }
  }
  print("yes");
}
