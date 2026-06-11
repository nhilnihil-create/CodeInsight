#include <bits/stdc++.h> 

using namespace std; 

int main(){ 
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(c<a){
    if(b<d){
     cout<<b-a;
    }
    else if(d<a) cout<<0;
    else cout<<d-a;
  }
  else if(b<c){
    cout<<0;
  }
  else{
    if(b<d) cout<<b-c;
    else cout<<d-c;
  }
}