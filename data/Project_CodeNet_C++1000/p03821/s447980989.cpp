#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


#define INF 1000000000000


signed main()
 {
   int n;
   cin>>n;
   int a[n],b[n];
   rep(i,n){
     cin>>a[i]>>b[i];
   }
   int ans=0;
   for(int i=n-1;i>=0;i--){
     if((a[i]+ans)%b[i]!=0){
     ans+=(b[i]-((a[i]+ans)%b[i]));
   }
   }
   cout<<ans;

 }
