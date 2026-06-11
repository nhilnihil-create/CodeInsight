#include <bits/stdc++.h>
using namespace std;

int main() {

  string a, b, c;
  cin>> a >> b >> c;
  
  int x=a.size();
  int y=b.size();
  
  if(a.at(x-1)==b.at(0)&&b.at(y-1)==c.at(0)){
    cout <<"YES" << endl;
  }
  
  else{
    cout << "NO" << endl;
  }
}