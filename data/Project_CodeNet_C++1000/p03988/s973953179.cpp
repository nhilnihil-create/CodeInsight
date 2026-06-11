#include <bits/stdc++.h>
using namespace std;

void fin(){
  cout<<"Impossible"<<endl;
  exit(0);
}

signed main(){
  int n;cin>>n;
  map<int,int> m;
  while(n--){
    int a;cin>>a;m[a]++;
  }
  int M=m.rbegin()->first;
  if(M==1){
    if(m[1]==2)cout<<"Possible"<<endl;
    else fin();
    return 0;
  }
  for(int i=M;i>M/2;i--)if(m[i]<2)fin();
  if(!(M&1)){if(m[M/2]!=1)fin();}
  else if(m[(M+1)/2]>2)fin();
  for(int i=(M-1)/2;i>0;i--)if(m[i])fin();
  cout<<"Possible"<<endl;
}
