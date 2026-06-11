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

int n,k;
int a[109];
int cnt[109];
bool pos[109];
bool yo(int x)
{
    if(x%2==1)
    {
        int tmp=k/2;
        f(i,0,tmp)
        {
            int val=k-i;
            if(cnt[val]<2)return false;
            cnt[val]-=2;
            if(i<tmp)pos[val]=true;
        }
        f(i,1,n-1)
        {
            if(cnt[i]>0 && pos[i]==false)return 0;
        }
    }
    else
    {
          int tmp=k/2;
        f(i,0,tmp-1)
        {
            int val=k-i;
            if(cnt[val]<2)return false;
            cnt[val]-=2;
            pos[val]=true;
        }
        if(cnt[k-tmp]<1)return false;
        cnt[k-tmp]-=1;
        f(i,1,n-1)
        {
            if(cnt[i]>0 && pos[i]==false)return false;
        }
    }
    return true;
}
 main()
{
    fast
    cin>>n;
    f(i,1,n)cin>>a[i],cnt[a[i]]++,k=max(k,a[i]);
    if(yo(k))cout<<"Possible\n";
    else     cout<<"Impossible\n";
    return 0;

}












