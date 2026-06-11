#include <bits/stdc++.h>
#define ll long long 
using namespace std;

#define pb push_back
ll solve(){
 ll n; cin>>n; 
 if(n<=6) return 1;
 else if(n>6 && n<=11) return 2;
 else{
   ll m=n/11;
   ll r=n%11;
   if(r==0) return 2*m;
   if(r<=6 ) return 2*m+1;
   else return 2*m+2;
 }

}


int main() {
   #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

 ios_base::sync_with_stdio(0);
 cin.tie(0);

int t=1 ;  while(t--){
 ll k=solve();
 cout<<k<<endl;
}

return 0;
}
