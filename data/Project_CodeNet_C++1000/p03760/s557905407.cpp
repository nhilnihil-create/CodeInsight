#include<bits/stdc++.h>
using namespace std;

int main(){
  string A,B;
  int i;
  cin >> A >> B;
  for(i = 0; i < B.size(); i++){
    cout << A.at(i) << B.at(i);
  }
  if(A.size() != B.size()){
    cout << A.at(i);
  }
  cout << endl;
}