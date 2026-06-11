#include <bits/stdc++.h>
using namespace std;
long long dfs(long long x, long long y)
{
    if(y%x == 0)
        return y/x*x*2-x;
    else
        return y/x*x*2+dfs(y%x, x);
}
int main()
{
    long long n, x;
    cin>>n>>x;
    cout<<n+dfs(x, n-x)<<endl;
    return 0;
}