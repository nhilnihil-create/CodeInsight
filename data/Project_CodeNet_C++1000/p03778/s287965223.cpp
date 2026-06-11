#include<bits/stdc++.h>
using namespace std;

int main(void){
   int W,a,b;
   cin>>W>>a>>b;
   int ans=max(a,b)-min(a,b)-W;
   if(ans<0) cout<<0<<endl;
   else cout<<ans<<endl;
   return 0;
}

