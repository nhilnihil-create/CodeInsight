#include <bits/stdc++.h>
using namespace std;

int main() {
  char a,b;
  char topCoDeer = 'H';
  cin >> a >> b;
  
  if(a == 'H'){
    if(b == 'H') topCoDeer = 'H';
    else topCoDeer = 'D';
  }else{
    if(b == 'H') topCoDeer = 'D';
    else topCoDeer = 'H';
  }
  
  cout << topCoDeer;
}
