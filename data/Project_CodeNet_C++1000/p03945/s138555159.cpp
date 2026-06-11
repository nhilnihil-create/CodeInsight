#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
 
int main() {
  //input
  string s; cin >> s;
  int n;
  n = s.size();
  int counter = 0;
  
  //compute
  for(int i = 0;i < n-1; i++) {
         if(s.at(i) != s.at(i+1)){
           counter += 1;
         }
  }
 
  //output
  cout << counter << endl;
  
}