// Bismillah .Ya Allah...
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int,int> PII;
const int mod = 1e9+7,INF = 1e9;
const int mx = 2e5+5;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,a,b;
    cin>>n>>a>>b;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    ll l = 1,r = 1e10;
    while(l<r)
    {
        ll mid = (l+r)/2;
        ll sum=0;
        for(int i=0;i<n;i++)
            sum+= max((ll)(arr[i]-b*mid+a-b-1)/(a-b),(ll)0);
        if(sum<=mid)
            r =mid;
        else
            l = mid+1;
    }
    cout<<l<<endl;
    return 0;
}
