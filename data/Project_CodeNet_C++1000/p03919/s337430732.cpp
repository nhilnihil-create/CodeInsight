#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  cin >>a>>b;
  int h;
  char w ='A';
  vector<vector<string>> s(a,vector<string>(b));
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      cin >> s.at(i).at(j);
      if( s.at(i).at(j)=="snuke"){
        h= i+1;
        w +=j;
      }
    }
  }
  cout << w<<h;
}