#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<long long> a(n), b(n);

    for (int i=0; i<n; i++) cin>>a[i]>>b[i];


    long long ans = 0;
    for (int i=n-1; i>=0; i--) {
        a[i] += ans;
        int d = a[i] % b[i];
        if (d == 0) continue;
        ans += b[i]-d;
    }
    cout<<ans<<endl;

}
