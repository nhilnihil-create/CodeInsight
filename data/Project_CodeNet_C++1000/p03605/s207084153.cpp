#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  cin>>n;
  bool ans=false;
  for(int i=0;i<n.size();i++){
    if(n[i]=='9'){
      ans=true;
    }
  }
  if(ans){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}