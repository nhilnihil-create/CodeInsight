#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, c, d, x;
    cin>>a>>b>>x>>c>>d>>x>>x;

    long long ans = a+b+c+d-a%2-c%2-d%2;

    if (a && c && d) {
        a--; c--; d--;
        long long ans2 = 3+a+b+c+d-a%2-c%2-d%2;
        ans = max(ans,ans2);
    }

    cout<<ans<<endl;
}
