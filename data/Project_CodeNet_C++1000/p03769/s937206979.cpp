#include<bits/stdc++.h>
using namespace std;
int p[210],q[210],cnt;
long long n;
void solve(long long n)
{
    if(n==0)
        return;
    if(~n & 1)
    {
        q[++q[0]]=cnt++;
        solve(n - 1);
    }
    else
    {
        p[++p[0]]=cnt++;
        solve(n >> 1);
    }
}
int main()
{
    cin>>n;
    solve(n);
    cout<<cnt+100<<endl;
    for(int i=1;i<=q[0];++i)
        cout<<cnt-q[i]<<" ";
    for(int i=p[0];i>0;--i)
        cout<<cnt-p[i]<<" ";
    for(int i=1;i<=100;++i)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}