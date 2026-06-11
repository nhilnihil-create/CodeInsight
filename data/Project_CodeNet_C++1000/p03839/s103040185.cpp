#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
int a[N];
long long sum[N], psum[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin>>n>>k;

    for (int i=1; i<=n; i++) {
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
        psum[i] = psum[i-1] + max(a[i], 0);
    }

    long long ans = 0;
    for (int l=1; l+k-1<=n; l++) {
        int r = l+k-1;
        long long cur = max(0LL, sum[r] - sum[l-1]);
        long long left = psum[l-1];
        long long right = psum[n] - psum[r];
//        cout<<l<<" "<<r<<" ----> "<<cur<<" "<<left<<" "<<right<<endl;
        ans = max(ans, cur+left+right);
    }
    cout<<ans<<endl;
}
