#include "bits/stdc++.h"
using namespace std;
int main() {
   // cout<<"Hello World!";
   int n,i,ans=0;
   cin>>n;
   int a[2*n];
   for(i=0;i<2*n;i++) cin>>a[i];
   sort(a,a+2*n);
   for(i=2*n-2;i>=0;i-=2)
   ans+=a[i];
   cout<<ans;
}
