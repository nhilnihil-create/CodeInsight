#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int main(){
  string str; cin >> str;
  int l = str.size();
  bool s = false;
  bool e = false;
  bool n = false;
  bool w = false;
  for(int i=0; i<l; i++){
    if(str.at(i) =='S') s=true;
    if(str.at(i) == 'E') e=true;
    if(str.at(i) == 'N') n=true;
    if(str.at(i) == 'W') w=true;
  }
  cout << ( s!=n || e!=w ? "No":"Yes") << endl;
}