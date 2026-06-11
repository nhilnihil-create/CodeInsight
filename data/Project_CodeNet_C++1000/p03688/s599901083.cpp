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

map<int,int>cnt;

 main()

{
    fast
    int n,x;
    int mx=0,mn=inf;
    cin>>n;
    f(i,1,n)
    {
        cin>>x;
        cnt[x]++;
        mx=max(mx,x);
        mn=min(mn,x);
    }
    if(mx-mn>1)
    {
        cout<<"No"<<endl;
        return 0;
    }
    if(mx==mn)
    {
       if(mx==(n-1))
       {
           cout<<"Yes"<<endl;
       }
       else if(n>=2*mx)
       {
           cout<<"Yes"<<endl;
       }
       else
       {
           cout<<"No"<<endl;
       }
    }
    else
    {
        int d=cnt[mn];
        int mcnt=cnt[mx];
        mcnt=mcnt/2;
        if(mx>= d+1  && mx<=d+mcnt)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }


















    return 0;

}











