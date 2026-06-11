#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;cin>>S;
  priority_queue<int> ans;
  int l=S.size();
  for(int i=2;i<l;i+=2){
    int j=i/2;
    string T1=S.substr(0,j);
    string T2=S.substr(j,j);
    if(T1==T2) ans.push(i);
  }
  cout<<ans.top()<<endl;
}
    
