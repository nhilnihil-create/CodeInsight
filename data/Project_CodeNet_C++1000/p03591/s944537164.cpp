#include<bits/stdc++.h>
using namespace std;
signed main(){
  string a; 
  cin>>a;
  if(a[0]=='Y'){
    if(a[1]=='A'){
      if(a[2]=='K'){
        if(a[3]=='I') cout<<"Yes";
        else cout<<"No";
      }
      else cout<<"No";
    }
    else cout<<"No";
  }
  else cout<<"No";
  cout<<"\n";
}