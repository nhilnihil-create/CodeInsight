#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a>>b;
  
  for (int i=0; i<b+2;i++){
    cout << "#";
  }
  cout <<endl;

  for (int i=0; i<a;i++){
    string c;
    cin >> c;
    cout << "#" + c + "#" << endl;
  }
  
  for (int i=0; i<b+2;i++){
    cout << "#";
  }
  cout <<endl;
  
}


