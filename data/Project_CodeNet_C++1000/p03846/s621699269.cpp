#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    long mod=1000000000+7;
    int ans[100000+1]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans[a[i]]++;
    }
    int f=0;
    for(int i=1;i<100000+1;i++){
        if(ans[i]%2!=0)f=1;
    }
    if(f==1)cout<<0<<endl;
    else {
        long mul=1;
        for(int i=0;i<n/2;i++){
            mul=(mul*2)%mod;
        }    
        cout<<mul<<endl;
    }
    return 0;
}