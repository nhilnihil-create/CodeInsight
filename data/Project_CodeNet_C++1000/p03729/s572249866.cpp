#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string A,B,C;
  cin >> A >> B >> C;
  int i=0;
  int j=0;
  
  int size_a = A.size()-1;
  int size_b = B.size()-1;
  
  if (A.at(size_a) == B.at(0)){
    i=1;
  }
  if (B.at(size_b) == C.at(0)){
    j=1;
  }
  
  if (i==1 && j==1){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}