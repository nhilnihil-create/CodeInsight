#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
int main()
{
    ll n,l,i,last,temp=1,a[100005];
    cin>>n>>l;
    for(i=1;i<=n;i++)
    cin>>a[i];
    for(i=1;i<n;i++)
    {
        if(a[i]+a[i+1]>=l)
        {
            temp=0;
            last=i;
        }
    }
    if(temp)
    {
        cout<<"Impossible\n";
        return 0;
    }
    cout<<"Possible\n";
    for(i=1;i<last;i++)
    cout<<i<<endl;
    for(i=n-1;i>=last;i--)
    cout<<i<<endl;
}
