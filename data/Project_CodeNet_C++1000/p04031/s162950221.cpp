#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<int(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for ( int i=0; i<n; i++ ) {
        cin >> a[i];
    }
    int ans=100100100;
    for ( int x=-100; x<=100; x++ ) {
        int res=0;
        for ( int i=0; i<n; i++ ) {
            res+=(x-a[i])*(x-a[i]);
        }
        ans=min(ans,res);
    }
    cout << ans << '\n';
    return 0;
}
