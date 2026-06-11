#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >>n>>m;
  vector<int> saki(n+1,0);
  vector<int> ato(n+1,0);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    if(a==1)saki[b]=1;
    if(b==n)ato[a]=1;
  }
  for(int i=1;i<=n;i++){
    if(saki[i]==1&&ato[i]==1){
      cout<<"POSSIBLE"<<endl;
      return 0;
    }
  }
  cout<<"IMPOSSIBLE"<<endl;
  return 0;
}
