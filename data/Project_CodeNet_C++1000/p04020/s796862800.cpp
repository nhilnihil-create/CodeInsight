#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    long long ans = 0, prv = 0;
    for (int i=1; i<=n; i++) {
        int x;
        cin>>x;

        if (x == 0) prv = 0;
        else if (x%2 == 0)      ans += x/2;
        else {
            ans += x/2;
            x = 1;
            if (prv)    ans++, prv = 0;
            else        prv = 1;
        }
    }
    cout<<ans<<endl;
}
