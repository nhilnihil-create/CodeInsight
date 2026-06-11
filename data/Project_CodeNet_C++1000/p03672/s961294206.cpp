#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
 
int main() {
  //input
  string str; cin >> str;
  int size;
  size = str.size();
  
  //compute
  vector<int> check(size);

  for(int i = 0; i < size; i++)  check[i] = 0;

for(int i = 0; i < size / 2 - 1; i++) {
  for(int j = 0; j < (size - 2 * i)/2 - 1; j++) {
      if(str.at(j) != str.at((size - 2 * i)/2 + j)){
          check[i] = -1;
          break;
      }
  }
}

  //output
  for(int i = 1; i < size/2; i++) {
      if(check[i] == 0){
          cout << size - 2 * i  << endl;
          return 0;
      }
  }

}
