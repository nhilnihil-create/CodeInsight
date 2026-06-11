#include<bits/stdc++.h>
using namespace std;
int main(){
  string x;
  cin>>x;
  int m=x.length(),j=1,k=0,b=1;
  while(j<m){
    while(j<m&&x.at(j)==x.at(k)) j++;
    if(j==m) break;
    b++;
    k=j;
    j++;
  }
  cout<<b-1<<endl;
}