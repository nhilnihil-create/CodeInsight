#include<bits/stdc++.h>

#define ll   long long int
#define PI 3.14159265358979
#define zig ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;


int main()
{
    zig
    int n, k, x, y, first;
    cin>>n>>k>>x>>y;
    first=min(n, k);
    int ans=first*x+(n-first)*y;
    cout<<ans<<'\n';
    return 0;
}
