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
    ll i,j,t,n,p;
    string s;
    bool flag=true;
    vector<ll>v(26);

    cin>>s;

    for(i=0;s[i];i++)
        v[s[i]-'a']++;

    for(i=0;i<26;i++)
    {
        if(v[i]&1)
        {
            flag=false;
            break;
        }
    }

    if(flag)
        cout<<"Yes";
    else
        cout<<"No";

    cout<<"\n";
    return 0;   //:D
}


