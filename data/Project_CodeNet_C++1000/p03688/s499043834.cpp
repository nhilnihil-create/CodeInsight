#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
struct edge {int from,to,cost;};

signed main() {
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
int amax=0;for(int i=0;i<n;i++)amax=max(amax,a[i]);
int b=0;
for(int i=0;i<n;i++){
    if(a[i]==amax){
        b++;
        continue;
    }
    if(a[i]!=amax-1){
        cout<<"No";
    return 0;
    }
    
}
if(b==1){
    cout<<"No";
    return 0;
}

if(amax>(n-b)+b/2||amax<(n-b)+1){
    if(n!=b||b!=amax+1){
        cout<<"No";
        return 0;
    }
}
cout<<"Yes";
return 0;
}
