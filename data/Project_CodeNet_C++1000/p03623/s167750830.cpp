#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C;
  cin >> A >> B >> C;
  int D = max(A,B) - min(A,B);
  int E = max(A,C) - min(A,C);
  if(D > E){
    cout << "B" << endl;
  }
  else{
cout << "A" << endl;
  }
}
