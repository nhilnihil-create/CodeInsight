#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,x;
  cin>>n;
  vector<int> a(n);
  set<int> b;
  for(i=0;i<n;i++) cin>>a.at(i);
  x=1;
  while(x!=2&&!b.count(x)){
    b.insert(x);
    x=a.at(x-1);
  }
  if(x==2) cout<<b.size()<<endl;
  else cout<<-1<<endl;
}