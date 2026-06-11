#include <bits/stdc++.h>
using namespace std;

int main(){
  string A,B;
  int count=0;
  cin >> B;
  A = "CODEFESTIVAL2016";
  for(int i=0;i<16;i++){
    if(A.at(i) != B.at(i)){
      count ++;
    }
  }
  cout << count << endl;
}