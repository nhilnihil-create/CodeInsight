#include <bits/stdc++.h>
#define ll long long 
using namespace std;

#define pb push_back

void solve(){
   int n; cin>>n; 
 string s; cin>>s; 
 ll x=0;

 ll max=0;
 for(int i=0;i<n;i++)
 {
   if(s[i]=='I') x++;
   else x--;
   if(x>max) max=x;
 }
 cout<<max<<endl;
}


int main() {
   #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

 ios_base::sync_with_stdio(0);
 cin.tie(0);

int t=1 ;  while(t--)
 solve();

return 0;
}
