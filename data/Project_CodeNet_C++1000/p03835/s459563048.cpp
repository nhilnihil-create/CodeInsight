#include <bits/stdc++.h>
#define ll long long 
using namespace std;

#define pb push_back

void solve(){
  ll k,s; cin>>k>>s;
  ll count=0;
  for(int i=0;i<=k;i++)
    for(int j=0;j<=k;j++)
      if(s-i-j>=0 && s-i-j<=k) count++;
cout<<count<<endl;
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
