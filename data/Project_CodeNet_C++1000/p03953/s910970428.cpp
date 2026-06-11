#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> x(n);
  for(Int i=0;i<n;i++) cin>>x[i];
  Int m,k;
  cin>>m>>k;
  vector<Int> a(m);
  for(Int i=0;i<m;i++) cin>>a[i];

  vector<Int> s(n-1);
  for(Int i=0;i<n-1;i++) s[i]=x[i+1]-x[i];
  
  vector<Int> ord(n-1);
  iota(ord.begin(),ord.end(),0);

  vector<Int> mov(ord);
  for(Int i=0;i<m;i++)
    swap(mov[a[i]-2],mov[a[i]-1]);

  //for(Int i=0;i<n-1;i++) cout<<ord[i]<<":"<<mov[i]<<endl;

  while(k){
    if(k&1){
      vector<Int> nxt(n-1);
      for(Int i=0;i<n-1;i++) nxt[i]=mov[ord[i]];      
      swap(ord,nxt);
    }
    vector<Int> nxt(n-1);
    for(Int i=0;i<n-1;i++) nxt[i]=mov[mov[i]];
    swap(mov,nxt);
    k>>=1;
  }

  Int pos=x[0];
  cout<<pos<<endl;
  for(Int i=0;i<n-1;i++){
    pos+=s[ord[i]];
    cout<<pos<<endl;
  }
  
  return 0;
}
