#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin>>H>>W;
  vector<vector<char>> a(H,vector<char>(W));
  vector<char> b(W+2,'#');
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++)
      cin>>a.at(i).at(j);
  }
  for(int i=0;i<W+2;i++)
    cout<<b.at(i);
  cout<<endl;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(j==0)
        cout<<'#';
      cout<<a.at(i).at(j);
      if(j==W-1)
        cout<<'#'<<endl;
    }
    
  }
   for(int i=0;i<W+2;i++)
    cout<<b.at(i);
}