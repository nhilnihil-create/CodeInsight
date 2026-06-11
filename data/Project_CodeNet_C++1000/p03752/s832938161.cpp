#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[15],L,ans,cnt,MIN=1e18;
int main(void){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<(1<<(n-1));i++){
        L=a[0];
        cnt=0;
        ans=0;
        for(int j=1;j<n;j++){
            if((i>>(j-1))&1){
                cnt++;
                if(L>=a[j]){
                    ans+=L-a[j]+1;
                    L++;
                }
            }
            L=max(L,a[j]);
        }
        if(cnt+1>=k){
            MIN=min(ans,MIN);
        }
    }
    cout<<MIN<<endl;
}
