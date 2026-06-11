#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,x=0,y=0;
  cin >> N;
  string s;
  cin >> s;
  for(int i=0; i<N; i++){
    if(s[i] == 'I'){
      x++; 
      if(x>y){
        y = x;
      }
    }
    else{
      x--;
    }
  }
  cout << y <<  endl;
}
