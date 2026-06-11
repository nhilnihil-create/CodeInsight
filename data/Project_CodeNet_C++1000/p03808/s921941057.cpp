///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=100009;
inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}


 main()

{
    fast
    int n;
    cin>>n;
    int a[n+5];
    int sum=0;
    f(i,1,n)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int yo=(n*(n+1))/2;
    if(sum%yo!=0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    int k=sum/yo;
    a[n+1]=a[1];
    for(int i=2;i<=n+1;i++)
    {
        int d=a[i]-a[i-1];
        int magic=k-d;
        if(magic<0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        if(magic%n!=0)
        {
            cout<<"NO"<<endl;
            return  0;
        }
    }
    cout<<"YES"<<endl;
















    return 0;

}











