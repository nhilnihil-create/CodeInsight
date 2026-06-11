#include <bits/stdc++.h>
#define ll long long 
using namespace std;




int main() {
   #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 ll a,b,x; 
 cin>>a>>b>>x;
 ll u=b/x;
 ll l=(a+(x-1))/x;
 cout<<u-l+1<<endl;

  return 0;
}
