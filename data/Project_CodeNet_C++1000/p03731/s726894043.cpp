#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,t;
    cin >> n >> t;
    long long a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    long long ans=0;
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]<=t) ans+=a[i]-a[i-1];
        else ans+=t;
    }
    ans+=t;
    cout << ans << endl;
}