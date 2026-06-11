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
const int M=200009;
inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}

int a[M+4];
int dan[M+3],bam[M+2];
 main()

{
    fast
    int n;
    cin>>n;
    f(i,1,n)
    {
        cin>>a[i];
    }
    stack<pi>s;
    f(i,1,n)
    {
        int cur=a[i];
        while(!s.empty())
        {
            int val=s.top().fi;
            if(val>cur)
            {
                s.pop();
            }
            else break;
        }
        if(s.empty())bam[i]=0;
        else bam[i]=s.top().si;
        s.push(mp(a[i],i));
    }
    while(!s.empty())s.pop();
    rf(i,n,1)
    {
         int cur=a[i];
        while(!s.empty())
        {
            int val=s.top().fi;
            if(val>cur)
            {
                s.pop();
            }
            else break;
        }
        if(s.empty())dan[i]=n+1;
        else dan[i]=s.top().si;
        s.push(mp(a[i],i));
    }
    int sum=0;
    f(i,1,n)
    {
        int lft=bam[i];
        int rgt=dan[i];
        int x=i-lft-1;
        int y=rgt-i-1;
        int cnt=x*y+x+y+1;
        sum+=(cnt*a[i]);

    }
    cout<<sum<<endl;

















    return 0;

}











