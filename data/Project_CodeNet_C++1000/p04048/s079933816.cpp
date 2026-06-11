#include<bits/stdc++.h>
using namespace std;
long long n,x;
long long ans;
void solve(long long a,long long b)
{
    if(a%b==0)
    {
        ans=ans+2*a-b;
        return;
    }
    ans+=a/b*b*2;
    solve(b,a%b);
}
int main()
{
    cin>>n>>x;
    ans=n;
    solve(max(n-x,x),min(n-x,x));
    cout<<ans;
}