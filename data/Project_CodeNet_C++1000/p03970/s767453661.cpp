#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  string A = "CODEFESTIVAL2016";
  int s = 0;
  for(int i = 0; i < A.size(); ++i){
    if(S.at(i) != A.at(i)) ++s;
  }
  cout << s << endl;
}