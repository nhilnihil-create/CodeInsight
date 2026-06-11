#include<bits/stdc++.h>
using namespace std;
main(){
  int n,x;
  cin>>n>>x;
  if(x==1||x==2*n-1)return cout<<"No",0;
  cout<<"Yes\n";
  if(n==2)return cout<<"1\n2\n3",0;
  
  vector<int> r(2*n-1,0);
  map<int,bool> m;
  bool f=x==2*n-2;
  m[r[n-2]=x+1-2*f]=true;
  m[r[n-1]=x]=true;
  m[r[n]=x-1+2*f]=true;
  m[r[n+1]=x+2-4*f]=true;
  for(int i=0,c=1;i<2*n-1;++i)if(!r[i]){
    while(m[c])c++;
    m[r[i]=c++]=true;
  }
  for(auto i:r)cout<<i<<"\n";
}