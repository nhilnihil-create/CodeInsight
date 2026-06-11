#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(){
  char string[120];
  cin >> string;
  int n = strlen(string);
 
  for(int i=0;i<n;i++){
    int count = 0;
    for(int j =0; j<n;j++){
      if(string[i] == string[j]){
        count++;
      }
    }
    if(count % 2 != 0){
      cout << "No";
      return 0;
     }
  }
  cout <<"Yes";
}