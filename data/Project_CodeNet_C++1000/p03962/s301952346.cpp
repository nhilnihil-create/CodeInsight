#include <bits/stdc++.h>
using namespace std;

int main(){
  int a1,a2,a3;
  cin >> a1 >> a2 >> a3;
  if(a1==a2&&a1==a3){
    cout << 1 << endl;
  }
  else if(a1==a2||a1==a3||a2==a3){
    cout << 2 << endl;
  }
  else{
    cout << 3 << endl;
  }
}