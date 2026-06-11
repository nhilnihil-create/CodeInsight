#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  // input
  string str; cin >> str;
  int size;
  size = str.size();
  vector<int> a(26) ;
  for(int i = 0;i < size; i++) cin >> a[i];
 
  // compute 

  for(int i = 0; i < size; i++){
    if(str.at(i) == 'a') a[0] += 1;
    if(str.at(i) == 'b') a[1] += 1;
    if(str.at(i) == 'c') a[2] += 1;
    if(str.at(i) == 'd') a[3] += 1;
    if(str.at(i) == 'e') a[4] += 1;
    if(str.at(i) == 'f') a[5] += 1;
    if(str.at(i) == 'g') a[6] += 1;
    if(str.at(i) == 'h') a[7] += 1;
    if(str.at(i) == 'i') a[8] += 1;
    if(str.at(i) == 'j') a[9] += 1;
    if(str.at(i) == 'k') a[10] += 1;
    if(str.at(i) == 'l') a[11] += 1;
    if(str.at(i) == 'm') a[12] += 1;
    if(str.at(i) == 'n') a[13] += 1;
    if(str.at(i) == 'o') a[14] += 1;
    if(str.at(i) == 'p') a[15] += 1;
    if(str.at(i) == 'q') a[16] += 1;
    if(str.at(i) == 'r') a[17] += 1;
    if(str.at(i) == 's') a[18] += 1;
    if(str.at(i) == 't') a[19] += 1;
    if(str.at(i) == 'u') a[20] += 1;
    if(str.at(i) == 'v') a[21] += 1;
    if(str.at(i) == 'w') a[22] += 1;
    if(str.at(i) == 'x') a[23] += 1;
    if(str.at(i) == 'y') a[24] += 1;
    if(str.at(i) == 'z') a[25] += 1;
  }

  for(int i = 0; i < 26; i++){
      if(a[i] >= 2){
          cout << "no" << endl;
          return 0;
      }
  }
  
  // output  
  cout << "yes" << endl;
  
}