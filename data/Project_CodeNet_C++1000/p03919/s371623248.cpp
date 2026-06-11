#include <bits/stdc++.h>
using namespace std;

int main(){
int H,W;
  cin>>H>>W;
  vector<vector<string>> X(H,vector<string>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>X.at(i).at(j);
    }
  }
  char a;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(X.at(i).at(j)=="snuke"){
        a = j+'A';
        cout<<a<<i+1<<endl;
      }
    }
  }
}