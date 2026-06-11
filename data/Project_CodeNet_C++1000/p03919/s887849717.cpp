#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  string alp="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  cin>>a>>b;
  vector<vector<string>> s(a,vector<string> (b));
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      cin>>s[i][j];
      if(s[i][j]=="snuke"){
        cout<<alp.at(j)<<i+1<<endl;
        return 0;
      }
    }
  }
}