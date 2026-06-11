#include<bits/stdc++.h>
using namespace std;

int main(){
  int k,s,x,y,w=0;
  cin>>k>>s;
  for(x=0;x<=k;x++) for(y=0;y<=min(k,s-x);y++) if(s-x-y<=k) w++;
  cout<<w<<endl;
}
