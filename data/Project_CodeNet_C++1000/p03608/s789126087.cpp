///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e15;
const int mod=1e9+7;
const int M=100005;
int dp[203][203];
 main()

{
    fast
    int n,m,r;
    cin>>n>>m>>r;
    vector<int>vec;
    f(i,1,r)
    {
       int x;
       cin>>x;
       vec.pb(x);
    }
    f(i,1,n)
    {
        f(j,1,n)
        {
            dp[i][j]=inf;
            dp[j][i]=inf;
        }
    }
    f(i,1,m)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dp[a][b]=min(dp[a][b],c);
        dp[b][a]=min(dp[b][a],c);
    }
    f(k,1,n)
    {
        f(i,1,n)
        {
            f(j,1,n)
            {

                if(dp[i][j]>dp[i][k]+dp[k][j])
                {
                    dp[i][j]=dp[i][k]+dp[k][j];
                }
            }
        }
    }
    int ses=inf;
    sort(vec.begin(),vec.end());
    do
    {

      int cost=0;
      for(int i=1;i<r;i++)
      {
          cost+=dp[vec[i]][vec[i-1]];
      }
      ses=min(ses,cost);

    }while(next_permutation(vec.begin(),vec.end()));

    cout<<ses<<endl;
    return 0;

}



































