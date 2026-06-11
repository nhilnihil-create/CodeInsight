#include<bits/stdc++.h>
using namespace std;
int main()

{
    int n, k, x, y;
    cin>>n>>k>>x>>y;
    long long int ans;
    if(n>=k)
        ans = x*k + (n-k)*y;
    else ans = n*x;
    cout<<ans<<endl;
    return 0;
}
