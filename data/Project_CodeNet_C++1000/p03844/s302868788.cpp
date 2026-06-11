#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  char c;
  cin >> a >> c >> b;
  if(c == '+'){
    a += b;
  }else{
    a -= b;
  }
  cout << a << endl;
}
