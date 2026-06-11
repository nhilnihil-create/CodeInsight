#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x,y) memset(x,y,sizeof(x))

ll num[1000005];

int main()
{
    ios_base:: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll i,j,k,s,d,r,m,n;
    cin>>n;
    for(i=1; i<=3*n; i++) cin>>num[i];
    sort(num+1, num+3*n+1);
    s=0;
    for(i=3*n-1, j=1; j<=n; i-=2, j++) s+=num[i];
    cout<<s<<endl;
}

