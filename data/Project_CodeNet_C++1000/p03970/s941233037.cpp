#include<iomanip>
#include <string>
#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include <stdio.h>
#include <numeric>
#include<math.h>
#include <ctype.h>
#include <algorithm> // sort
#include <map> // pair
using namespace std;
#define nin(n) int n; cin >> n;
#define kin(k) int k; cin >> k;
int main() {
  string s,t;
  t="CODEFESTIVAL2016";
    cin >> s;
  int ans=0;
  for(int i=0;i<s.size();i++){
    if(s.at(i)!=t.at(i)){
      ans++;
    }
  }
  cout << ans << endl;
}