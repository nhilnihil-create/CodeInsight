#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long a[n];
    long long b[n];
    long long mod=1e9+7;
    for(int i=0;i<n;i++) b[i]=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[a[i]]++;
    }
    bool flag=true;
    long long ans=1;
    if(n%2==1){
        for(int i=0;i<n;i++){
            if(b[0]!=1) flag=false;
            if(i%2==0&&i>0&&b[i]!=2) flag=false;
            if(i%2==1&&b[i]!=0) flag=false;
        }
        if(!flag) ans=0;
        else{
            for(int i=0;i<(n-1)/2;i++){
                ans=ans*2%mod;
            }
        }
    }
    else if(n%2==0){
        for(int i=0;i<n;i++){
            if(i%2==0&&b[i]!=0) flag=false;
            if(i%2==1&&b[i]!=2) flag=false;
        }
        if(!flag) ans=0;
        else{
            for(int i=0;i<n/2;i++){
                ans=ans*2%mod;
            }
        }
    }
    cout << ans%mod << endl;
}