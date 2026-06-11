#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  int n=0;
  int e=0;
  int w=0;
  int s=0;
  
  for(int i=0; i<str.size(); i++){
    if(str.at(i) == 'N'){
      n++;
    }
    if(str.at(i) == 'E'){
      e++;
    }
    if(str.at(i) == 'W'){
      w++;
    }
    if(str.at(i) == 'S'){
      s++;
    }
  }
  
  if(n*s == 0){
    if(n*n + s*s != 0){
      cout << "No" << endl;
    }
    else{
      if(e*w == 0){
        cout << "No" << endl;
      }
      else{
        cout << "Yes" << endl;
      }
    }
  }
  
  else{
    if(e*w != 0){
      cout << "Yes" << endl;
    }
    else{
      if(e*e + w*w == 0){
      cout << "Yes" << endl;
    }
      else{
        cout << "No" << endl;
      }
    }
  }
	return 0;
}
