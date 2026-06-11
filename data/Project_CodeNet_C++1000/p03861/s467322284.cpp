#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ll a,b,x;
cin>>a>>b>>x;
if(a==0)
{
    cout<<b/x+1;
}
else
{
    cout<<(b/x)-((a-1)/x);
}
return 0;
}
