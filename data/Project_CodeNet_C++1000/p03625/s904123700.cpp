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
    ll n,ans[3],x=0;
    cin>>n;
    ll a[n+2];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-2;i>=0;i--)
    {
       if(a[i]==a[i+1])
       {
           ans[x++]=a[i];
           if(x==2)
            break;
           i=i-1;
       }
    }
    if(x==2)
    cout<<ans[0]*ans[1]<<endl;
    else
    cout<<"0\n";
    return 0;
}
