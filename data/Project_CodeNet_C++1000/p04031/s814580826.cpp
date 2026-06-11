 /******************************************************************************

                         بسم الله الرحمن الرحيم
                     Author: Mst: Mhamuda Khatun
                               RUCSE27

*******************************************************************************/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ull unsigned long long
#define OrderSetTree tree<ll,null_type/*mapped_type*/,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define pi 2*acos(0.0)
#define f first
#define s second
#define pb push_back
#define gap ' '
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define mod 1000000007
#define MAX 1000000000000
#define N 305

int main()
{
    fastio;
    //OrderSetTree ost;
    ll i,x,y,n,p,sum=0,ans=0,ans2=0;
    vector<ll>v;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>p;
        v.pb(p);
        sum+=p;
    }

    x=floor(sum/n);
    y=ceil(((double)sum)/n);

    for(i=0;i<n;i++)
    {
        ans+=(v[i]-x)*(v[i]-x);
        ans2+=(v[i]-y)*(v[i]-y);
    }

    cout<<min(ans,ans2);
    cout<<"\n";
    return 0;   //:D
}


