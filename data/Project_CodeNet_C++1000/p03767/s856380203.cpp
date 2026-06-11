#include <bits/stdc++.h>
using namespace std;
const int m=3e5+1;
int  a[m];
main(){
    int n; cin >> n;
    for(int i=0;i<3*n;i++) cin >> a[i];
    sort(a,a+3*n);
    long long ans = 0ll;

    for(int i=n;i<3*n;i+=2)
        ans+=a[i];
    cout << ans << endl;
}