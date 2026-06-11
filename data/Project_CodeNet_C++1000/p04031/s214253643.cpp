#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    int la=INT32_MAX;
    int ba=0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        la=min(la,a[i]);
        ba=max(ba,a[i]);
    }

    int ans=INT32_MAX;
    for(int i = la; i <= ba; i++) {
        int ref=i;
        int count=0;
        for(int j = 0; j < n; j++) {
            count+=(a[j]-ref)*(a[j]-ref);
        }
        ans=min(ans,count);
    }
    cout << ans << "\n";
    return 0;
}