#include <bits/stdc++.h>
using namespace std;

int main() {
  string a="CODEFESTIVAL2016";
  string b;
  cin>>b;
  int c=0;
  for(int i=0;i<16;i++){
    if(!(a.at(i)==b.at(i))){
      c++;
    }
  }
  cout<<c<<endl;
}