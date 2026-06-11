#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;cin>>h>>w;
  string s[h][w];
  int x,y;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
      if(s[i][j]=="snuke"){
        x=i;y=j;
      }
    }
  }
  char a=y+'A';
  cout<<a<<x+1<<endl;
}