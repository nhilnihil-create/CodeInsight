#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a[51],b[51];
ll n,m;
ll f(ll x,ll y)
{
for(int i=0;i<m;i++)
for(int j=0;j<m;j++)
{

    if(a[x+i][y+j]!=b[i][j])return 0;
}

return 1;
}
int main()
{

cin>>n>>m;
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<m;i++)cin>>b[i];

for(int i=0;i<=n-m;i++)
for(int j=0;j<=n-m;j++)
if(f(i,j))return 0&puts("Yes");
puts("No");


}