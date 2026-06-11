#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x;
  int a;
  int b;
  cin >> x >> a >> b;
  if(b-a>x){
    cout << "dangerous" << endl;
  }
  else if(b>a){
   cout << "safe" << endl; 
  }
  else{
    cout << "delicious" << endl;
  }

}