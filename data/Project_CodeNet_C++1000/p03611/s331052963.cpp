#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
   int n;
   cin>>n;
   vector<int> a(1000000,0);
   rep(i,n){
      int x;
      cin>>x;
      a[x]++;
   }
   
   ll ans=0;
   rep(i,100000){
      ll kari=a[i]+a[i+1]+a[i+2];
      ans=max(ans,kari);
   }
   cout<<ans<<endl;
}


