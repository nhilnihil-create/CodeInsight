#include<bits/stdc++.h>
using namespace std;
int main(){
  string b;
  cin>>b;
  int l=b.length(),x=0,j;
  for(j=0;j<l;j++){
    if(b[j]=='g') x++;
    else if(b[j]=='p') x--;
  }
  cout<<x/2<<endl;
}