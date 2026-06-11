#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


int main() {
  string s_; cin>>s_;
  int n=s_.size();
  int ans=n;
  if(count(s_.begin(),s_.end(),s_.at(0))==n||s_.size()==1){ans=0;}
  else{
  rep(i,(n+1)/2){
    string s=s_;
    
    while(true){
    
      rep(j,s.size()){
        if(s.at(j)==s.at(i) && j>0){s.at(j-1)=s.at(i);}
      }
      s.erase(s.size()-1);//cout<<s<<endl;
      int m=s.size();
      
      if(count(s.begin(),s.end(),s.at(i))==m){
        ans=min(ans,n-m);
        break;
      }
    
    }
  }
  }
  cout<<ans;
}