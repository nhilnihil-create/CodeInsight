#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  
  bool Alice = false;
  bool Bob = false;
  int cnt = 0;
  for(int i=0;i<=100;i++){
    if(i>=A) Alice = true;
    if(i>=B) Alice = false;
    if(i>=C) Bob = true;
    if(i>=D) Bob = false;
    
    if(Alice==true && Bob==true) cnt ++;
  }
  cout << cnt << endl;
}