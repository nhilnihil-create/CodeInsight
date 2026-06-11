#include <bits/stdc++.h>
using namespace std;

int main() {
  string O, E;
  cin >> O >> E;
  int len = O.size();
  
  string S = O+E;
  if (E.size() == len){
    for (int i=0; i<len; i++) {
      S.at(2*i) = O.at(i);
      S.at(2*i+1) = E.at(i);
    }
  }
  else{
    for (int i=0; i<len-1; i++) {
      S.at(2*i) = O.at(i);
      S.at(2*i+1) = E.at(i);
    }
    int i=len-1;
    S.at(2*i) = O.at(i);
  }
  cout << S << endl;
}