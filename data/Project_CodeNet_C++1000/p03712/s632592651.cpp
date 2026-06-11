#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W,N;
  cin >> H >> W;
  N=W+2;
  
  for(int i = 0; i < N; i++){
  cout << "#" ;
  }
  
  cout << endl;
  string str;
  
  for(int i= 0; i < H; i++){
  cin >> str;
  cout << "#" << str << "#" << endl;
  }
  
  for(int i = 0; i < N; i++){
  cout << "#" ;
  }
  cout << endl;
}