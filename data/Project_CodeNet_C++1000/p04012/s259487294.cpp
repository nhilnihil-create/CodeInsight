#include<bits/stdc++.h>
using namespace std;

int main(){
  string w;cin>>w;
  int l=w.size();
  vector<int> alpha(26,0);
  for(int i=0;i<l;i++){
    alpha.at(w.at(i)-'a')++;
  }
  
  bool ans=true;
  for(int i=0;i<26;i++){
    if(alpha.at(i)%2!=0){
      ans=false;
      break;
    }
  }
  cout<<(ans?"Yes":"No")<<endl;
}