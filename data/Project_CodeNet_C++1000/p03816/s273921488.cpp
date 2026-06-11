#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int n;cin>>n;
    int a[n];
    int ans[100000+1]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans[a[i]]++;
    }
    ll sum=0;
    for(int i=0;i<100000+1;i++){
        if(ans[i]>1)sum+=ans[i]-1;
    }
    if(sum%2==0)cout<<n-sum<<endl;
    else cout<<n-sum-1<<endl;
}