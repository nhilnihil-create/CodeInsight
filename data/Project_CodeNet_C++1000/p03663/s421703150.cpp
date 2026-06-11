#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string ans,query;
  while(ans.size()<11){
    if(!ans.empty()){
      query=ans+"0";
      while(query.size()<18) query+="9";
      cout<<"? "<<query<<endl;
      char f;
      cin>>f;
      if(f=='Y'){
	ans+="0";
	continue;
      }
    }
    int l=0,r=9;
    while(l+1<r){
      int m=(l+r)/2;
      query=ans;
      query+=(char)('0'+m);
      while(query.size()<18) query+="9";
      cout<<"? "<<query<<endl;
      char f;
      cin>>f;
      if(f=='Y') r=m;
      else l=m;
    }
    ans+=(char)('0'+r);
  }
  int l=0;
  while(l<11){
    l++;
    query="1";
    for(int i=0;i<l-1;i++) query+="0";
    cout<<"? "<<query<<endl;
    char f;
    cin>>f;
    if(f=='N'){
      cout<<"! "<<ans.substr(0,l-1)<<endl;
      return 0;
    }
  }
  l=0;
  while(l<11){
    l++;
    query="2";
    for(int i=0;i<l-1;i++) query+="0";
    cout<<"? "<<query<<endl;
    char f;
    cin>>f;
    if(f=='Y'){
      cout<<"! "<<ans.substr(0,l)<<endl;
      return 0;
    }
  }
  
  return 0;
}
