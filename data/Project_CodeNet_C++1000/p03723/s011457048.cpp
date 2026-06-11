#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  
  int count = 0;
  
  if(a % 2 == 1 && a == b && b == c){
    cout << 0 << endl;
  }
  else if(a == b && b == c){
    cout << -1 << endl;
  }
  else{ 
    while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0){
      int aa = a;
      int bb = b;
      int cc = c;
      a = (bb + cc) / 2;
      b = (aa + cc) / 2;
      c = (aa + bb) / 2;
      count++;
    }
    cout << count << endl;
  }
}