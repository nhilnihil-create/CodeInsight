#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5+1000;

int s[maxn];

int main() {
    int n;
    long long sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        sum+=s[i];
    }
    long long ans=999999999999;
    long long su=s[0];
    for(int i=1;i<n-1;i++){
        su+=s[i];
        ans=min(abs(sum-2*su),ans);
    }
    if(n==2){
        cout<<abs(s[0]-s[1])<<endl;
    }
    else
    cout<<ans<<endl;
    return 0;
}