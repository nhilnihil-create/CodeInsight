#include <bits/stdc++.h>  
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


int main(){
  int n; cin>>n;
  vector<int> v(n);
  rep(i,n){cin>>v[i];}
  sort(v.begin(),v.end());
  int i=0;
  while(i<v.size()-1){
    if(v.size()==0){break;}
    if(v[i]==v[i+1]){
      v.erase(v.begin()+i);
      v.erase(v.begin()+i);
    }
    else{i++;}
  }
  cout<<v.size();

}



