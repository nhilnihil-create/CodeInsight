#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int l=s.length(),i,j;
  for(i=l-2;i>0;i-=2){
    for(j=0;j<i/2;j++) if(s.at(j)!=s.at(i/2+j)) break;
    if(j==i/2) break;
  }
  cout<<i<<endl;
}