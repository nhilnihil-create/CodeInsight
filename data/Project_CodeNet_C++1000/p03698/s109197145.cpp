#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int a=S.size(),c=0;
  vector<char> b(a);
  for (int i=0;i<a;i++){
  b.at(i)=S.at(i);
  }
  sort(b.begin(),b.end());
  for (int i=0;i<a-1;i++){
  if (b.at(i)==b.at(i+1)){
  c++;
  }
  }
  
  if(c>0){
  cout << "no" << endl;
  }
  else {
  cout << "yes" << endl;
  }
  
}