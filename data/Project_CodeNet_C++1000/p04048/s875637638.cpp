#include<bits/stdc++.h>
using namespace std;
#define int long

signed main(){
  int n,x;
  cin>>n>>x;
  int a=x,b=n-x,c=n;
  int res=x;
  if(a==b)return cout<<x*3,0;
  while(true){
    if(a>b){
      int t=a/b;
      if(t>1)--t;
      res+=t*b*2;
      cerr<<t<<"\n";
      a-=t*b;
      c-=t*b;
      cerr<<"a,c:"<<a<<","<<c<<"\n";
    }
    else if(a<b){
      res+=c;
      int an,bn,cn;
      an=2*b-c;
      bn=c-b;
      cn=b;
      a=an;
      b=bn;
      c=cn;
    }
    else{
      res+=b*2;
      return cout<<res,0;
    }
  }
  
}