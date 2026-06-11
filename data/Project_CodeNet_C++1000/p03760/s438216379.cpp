#include<bits/stdc++.h>
using namespace std;

string o,e;

int main(){
  cin >> o >> e;

  string ans="";
  for(int i=0;i<o.length()+e.length();i++){
    if(i%2==0)ans+=o[i/2];
    else ans+=e[(i-1)/2];
  }

  cout << ans << endl;
}