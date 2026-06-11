#include <bits/stdc++.h>
using namespace std;
  

int main() {
  int a,b,c;
  
  cin >> a >> b >> c;

  vector<int> ame={a,b,c};
  
  sort(ame.begin(),ame.end());
  
  if(ame.at(2)==ame.at(1)+ame.at(0))
    cout << "Yes" ;
  else
    cout << "No";
  
  
  
}