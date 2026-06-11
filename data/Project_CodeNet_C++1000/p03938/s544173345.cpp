#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1000000;
const int MOD = 1000000007;

signed main() {
 int n;
 cin>>n;
 int p,q[n];
 for(int i=0;i<n;i++){
     cin>>p;p--;q[p]=i;
 }

 int a[n],b[n];
 a[0]=500000000ll;b[0]=a[0];
 for(int i=1;i<n;i++){
     a[i]=a[i-1]+1;b[i]=b[i-1]-1;
     if(q[i]-q[i-1]<0)b[i]+=q[i]-q[i-1];
     else a[i]+=q[i]-q[i-1];
 }
 for(int i=0;i<n;i++)cout<<a[i]<<' ';
 cout<<endl;
for(int i=0;i<n;i++)cout<<b[i]<<' ';

return 0;
}
