#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,a,b;
  cin >> x >> a >> b;
  int A=max(a-x,x-a),B=max(b-x,x-b);
  
  if(A<B){
  cout << "A" << endl;
  }
  else{
    cout << "B" << endl;
  }
}
