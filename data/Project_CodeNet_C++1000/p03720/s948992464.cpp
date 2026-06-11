#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  
  cin>> N >> M;
  
  vector<int> n(N);
  
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    
    n.at(a-1)++;
    n.at(b-1)++;
    
  }
  
  for(int i=0;i<N;i++){
    cout<<n[i]<<endl;
  }
  
}