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

int a[M+3];

 main()

{
    fast
    int n;
    cin>>n;
    int ses=0;
    int last=0;
    int sum=0;
    f(i,1,n)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            ses+=(sum/2);
            sum=0;
        }
        else
        {
            sum+=a[i];
        }
    }
    ses+=(sum/2);
    cout<<ses<<endl;
    return 0;

}











