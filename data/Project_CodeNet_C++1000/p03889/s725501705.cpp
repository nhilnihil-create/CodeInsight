#include "bits/stdc++.h"
using namespace std;
#define int long long
int mod=1e9+7;

signed main(){
  string s;
  cin>>s;
  string t=s;
  reverse(t.begin(),t.end());
  for(int i=0;i<t.size();i++){
    if(t[i]=='b'){
      t[i]='d';
    }else if(t[i]=='d'){
      t[i]='b';
    }else if(t[i]=='p'){
      t[i]='q';
    }else if(t[i]=='q'){
      t[i]='p';
    }
  }
  if(s==t)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
