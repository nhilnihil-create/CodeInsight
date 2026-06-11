#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m; cin>>n>>m;
  vector<int> num(n+1,0);
  for(int i=0;i<m;i++){
    int x,y; cin>>x>>y;
    num[x]++; num[y]++;
    if(num[x]==2) num[x]-=2;
    if(num[y]==2) num[y]-=2;
  }
  sort(num.begin(),num.end());
  if(0==num[n]){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
} 