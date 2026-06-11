#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  set<int> p1;
  set<int> pn;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    if(a==1||b==1)
      p1.insert(max(a,b));
    if(a==n||b==n)
      pn.insert(min(a,b));
  }
  bool f=0;
  for(int x:p1)
    f=(pn.count(x)?1:f);
  cout<<(f?"POSSIBLE":"IMPOSSIBLE")<<endl;
}