#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long mod=1e9+7;
    long long a[1001];
    for(int i=0;i<=1000;i++) a[i]=0;
    long long ans=1;
    for(int i=2;i<=n;i++){
        for(int j=i+i;j<=n;j+=i) a[j]=1;
    }
    long long com;
    for(int i=2;i<=n;i++){
        if(a[i]==0){
            com=0;
            for(int j=i;j<=n;j*=i){
                com+=n/j;
            }
            ans=ans*(com+1)%mod;
        }
    }
    cout << ans << endl;
}