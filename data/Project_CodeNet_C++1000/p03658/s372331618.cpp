#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,d=0;
  cin>>a>>b;
  vector<int> c(a);
  for(int i=0;i<a;i++){
    cin>>c.at(i);
  }
  sort(c.rbegin(),c.rend());
  for(int i=0;i<b;i++){
    d+=c.at(i);
  }
  cout<<d<<endl;
}