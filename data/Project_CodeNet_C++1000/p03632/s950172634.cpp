#include<bits/stdc++.h>
using namespace std;

int main(void){
   int A,B,C,D;
   cin>>A>>B>>C>>D;
   int ans=min(B,D)-max(A,C);
   if(ans>0) cout<<ans<<endl;
   else cout<<0<<endl;
   return 0;
}

