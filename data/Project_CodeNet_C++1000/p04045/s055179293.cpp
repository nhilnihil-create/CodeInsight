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
    ll i,j,t,n,k,p,num;
    bool flag=true;
    vector<bool>v(10);

    cin>>n>>k;

    for(i=0;i<k;i++)
    {
        cin>>p;
        v[p]=true;
    }

    for(i=n; ;i++)
    {
        num=i;
        flag=true;

        while(num>0)
        {
            if(v[num%10])
            {
                flag=false;
                break;
            }
            num/=10;
        }
        if(flag)
            break;
    }

    cout<<i;
    cout<<"\n";
    return 0;   //:D
}


