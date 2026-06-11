#include <bits/stdc++.h>
using namespace std;
int main(){
  string O,E;
  cin >> O >> E;
  int o = 0;
  int e = 0;
  for(int i = 0; i < O.size() + E.size(); i++){
    if(i % 2 == 0){
      cout << O[o];
      o++;
    }
    else{
      cout << E[e];
      e++;    
    }
  }
}