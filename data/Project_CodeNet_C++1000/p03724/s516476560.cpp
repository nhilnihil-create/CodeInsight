#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m; cin>>n>>m;
  vector<int> num(n+1,0);
  for(int i=0;i<m;i++){
    int x,y; cin>>x>>y;
    num[x]++; num[y]++;
  }
  for(int i=0;i<=n;i++){
    if(num[i]%2==1){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
}