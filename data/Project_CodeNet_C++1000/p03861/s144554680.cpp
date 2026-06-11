#include<bits/stdc++.h>
 
using namespace std;

void solve(){
  long long int a , b, x,p;
  cin>>a>>b>>x;
  p=a;
  if(a!=0){
    a--;
  }
  long long int ans = (b/x) - (a/x) ;
  if(p==0){
    ans++;
  }
  cout<<ans<<endl;
}
int main(){
    
    solve();
    
}    