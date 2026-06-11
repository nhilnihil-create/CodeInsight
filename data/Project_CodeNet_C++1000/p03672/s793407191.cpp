#include<bits/stdc++.h>
using namespace std;

int main(){
  string str;
  cin >> str;
  int n;
  n = str.size();
  if(n%2 == 1) n-=1;
  for(int i = n-2; i >= 0; i = i-2){
    if(str.substr(0,i/2) == str.substr(i/2,i/2)){
      cout << i << endl;
      return 0;
      }
  }
}