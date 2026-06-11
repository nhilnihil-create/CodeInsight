#include<bits/stdc++.h>
using namespace std;
int k,t,a[10005];
int main() {
    cin>>k>>t;
    for(int i=1;i<=t;i++)cin>>a[i];
    sort(a+1,a+t+1);
    cout<<max(a[t]*2-1-k,0)<<endl;
    return 0; 
}