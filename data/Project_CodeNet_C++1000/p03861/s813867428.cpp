#include <bits/stdc++.h>

using namespace std;

int main(){
    long long a,b,x,tmp,ans;

    cin>>a>>b>>x;

    ans=b/x - a/x;
  
  if(a%x == 0){
    ans=ans+1;
  }
    

    cout<<ans<<endl;

    return 0;
}