#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
int ans[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin>>a>>b;

    int ans = 2e9+10;
    if (b>=a)   ans = min(ans, b-a);
    if (-b>=a)  ans = min(ans, -b-a+1);
    if (b>=-a)  ans = min(ans, b+a+1);
    if (-b>=-a) ans = min(ans, -b+a+2);

    cout<<ans<<endl;
}
