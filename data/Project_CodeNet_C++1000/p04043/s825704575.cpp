#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
   int a,b,c;
   cin>>a>>b>>c;
   if((max(a,max(b,c))==7) && (min(a,min(b,c))==5) && (a+b+c == 17) ){
       cout<<"YES";
   } else {
       cout<<"NO";
   }
}
int main(){
   int t=1;
//   cin>>t;
   while(t--){
       solve();
   }
   return 0;
}