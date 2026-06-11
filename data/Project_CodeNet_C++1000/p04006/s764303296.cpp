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
const int M=2009;
inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}

 struct MinQ
{ int window;deque<pair<int,int> >dq;
  MinQ(int x){window=x;}
  void push(int idx,int x)
  {while(!dq.empty() && dq.back().first>=x)dq.pop_back();dq.push_back(make_pair(x,idx));}
  int qry(int idx){while(idx-dq.front().second>=window)dq.pop_front();return dq.front().first;}
};

int n,x;
int a[2*M+7];
int yo(int d)
{   int ret=d*x;
    d++;
    MinQ Magic(d);
    f(i,1,d-1)
    {
        Magic.push(i,a[i]);
    }
    f(i,d,n+d-1)
    {
        Magic.push(i,a[i]);
        int mn=Magic.qry(i);
        ret+=mn;
    }
    return ret;
}
 main()

{
    fast
    cin>>n>>x;
    f(i,1,n)cin>>a[i],a[n+i]=a[i];
    int ses=inf;
    f(i,0,n-1)
    {
        ses=min(ses,yo(i));
    }
    cout<<ses<<endl;
    return 0;
}
