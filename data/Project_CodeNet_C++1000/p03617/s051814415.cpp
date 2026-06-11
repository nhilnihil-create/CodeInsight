#include <bits/stdc++.h>
using namespace std;

int main() {
    int q,h,s,d;
    cin >> q >> h >> s >> d;
    long long n;
    cin >> n;
    long long ans=1LL<<60;
    long long x=min({4*q,2*h,s});
    {
        long long res=n*x;
        ans=min(ans,res);
    }
    {
        long long res=n/2*d+(n%2)*x;
        ans=min(ans,res);
    }
    cout << ans << '\n';
    return 0;
}