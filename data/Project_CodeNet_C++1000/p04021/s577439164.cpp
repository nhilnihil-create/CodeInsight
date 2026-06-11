#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x,y) memset(x,y,sizeof(x))
#define left (2*pos)
#define right (2*pos+1)
#define M ((L+R)/2)
#define sz 1000005
ll seg[1000005], se[sz], posi[sz], num[sz];
map<ll,ll>mp;
int main()
{
    ios_base:: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll i,j,k,s,d,r,m,n;
    cin>>n;
    for(i=1; i<=n; i++) cin>>num[i], se[i] = num[i];

    sort(num+1, num+n+1);
    for(i=1; i<=n; i++) mp[num[i]] = i;
    for(i=1; i<=n; i++) se[i] = mp[se[i]], posi[se[i]] = i;
    s=0;
    for(i=n; i>=1; i--)
    {
        if(i%2 != posi[i]%2) s++;
    }
    cout<<s/2<<endl;
}


