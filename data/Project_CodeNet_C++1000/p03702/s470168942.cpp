#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5+5;
long long n,a,b;
long long h[MAXN];
long long temph[MAXN];
bool check(long long x){


    for(long long i=1;i<=n;i++){
        temph[i] = h[i] - (x*b);

    }
    long long ans = 0;
    for(long long i=1;i<=n;i++){
        if(temph[i]>0){
            ans+=(temph[i])/(a-b);
            if(temph[i]%(a-b)){
                ans++;
            }
        }
    }

    return ans<=x;
}
int main(){
    cin>>n>>a>>b;
    for(long long i=1;i<=n;i++){
        cin>>h[i];
    }
    long long l=0;
    long long ans = -1;
    long long r = 1e9;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid)){
            r=mid-1;
            ans= mid;
        }else{
            l = mid+1;
        }
    }
    cout<<ans<<endl;
}
