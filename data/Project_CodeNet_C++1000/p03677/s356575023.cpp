#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 3e5+5;
long long arr[MAXN];
long long pref[MAXN];
long long pref2[MAXN];
long long ans;
long long res= 1e18;
int main(){
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(long long i=1;i<n;i++){
        long long x = arr[i];
        long long y = arr[i+1];
        if(y<x){
            y+=m;
            if(y-x==1){
                ans++;
                continue;
            }
        }
            pref[x+2]++;
            pref[y+1]--;
            pref2[y+1]+=y-x-1;
            pref[m+x+2]++;
            pref[m+y+1]--;
            pref2[m+y+1]+=y-x-1;
        ans+=(y-x);


    }
    for(long long i=1;i<=3*m;i++){
        pref[i] += pref[i-1];
        pref2[i] += pref2[i-1];
        pref2[i]-=pref[i];
        res = min(res,ans+pref2[i]);
    }
    cout<<res<<endl;
}
