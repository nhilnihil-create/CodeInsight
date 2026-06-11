#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,a,b;
  cin>>n>>m;
  set<int> z;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    if(a==1){
      if(z.count(b)){
        cout<<"POSSIBLE"<<endl;
        return 0;
      }
      else z.insert(b);
    }
    else if(b==n){
      if(z.count(a)){
        cout<<"POSSIBLE"<<endl;
        return 0;
      }
      else z.insert(a);
    }
  }
  cout<<"IMPOSSIBLE"<<endl;
}