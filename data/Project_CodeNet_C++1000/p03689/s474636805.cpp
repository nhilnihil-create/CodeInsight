#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,a,b;cin>>n>>m>>a>>b;
  vector<vector<int>>v(n, vector<int>(m));
  for(int i=a-1;i<n;i+=a){
    for(int j=b-1;j<m;j+=b){
      v[i][j]=-1000000;
    }
  }
  for(int i=0;i<n;i+=a){
    for(int j=0;j<m;j+=b)v[i][j]=999999;
  }
  if(n%a||m%b){
    cout<<"Yes"<<endl;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(j)cout<<' ';
        cout<<v[i][j];
      }
      cout<<endl;
    }
  }
  else cout<<"No"<<endl;
}
  
