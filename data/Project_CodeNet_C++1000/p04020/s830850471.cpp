#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
int a[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    long long ans = 0;
    for (int i=1; i<=n; i++) {
        cin>>a[i];
        if (a[i] == 0)  continue;
        else if (a[i]%2) ans += a[i]/2, a[i] = 1;
        else        ans += a[i]/2-1, a[i] = 2;
    }

    for (int i=1; i<=n; i++) {
        if (a[i] == 0)  continue;
        if (a[i] == 2)  ans++;
        else if (a[i] == 1 && a[i+1])   ans++, a[i+1]--;
    }
    cout<<ans<<endl;
}
