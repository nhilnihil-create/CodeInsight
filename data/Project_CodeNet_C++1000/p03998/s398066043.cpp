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
    string alice,bob,charlie,ans="";

    cin>>alice>>bob>>charlie;

    ans+=alice.front();
    alice.erase(0,1);

    while(1)
    {
        if(ans.back()=='a')
        {
            if(alice.empty())
                break;
            else
            {
                ans+=alice.front();
                alice.erase(0,1);
            }
        }
        else if(ans.back()=='b')
        {
            if(bob.empty())
                break;
            else
            {
                ans+=bob.front();
                bob.erase(0,1);
            }
        }
       else
        {
            if(charlie.empty())
                break;
            else
            {
                ans+=charlie.front();
                charlie.erase(0,1);
            }
        }
    }

    cout<<(char)(ans.back()-32);
    cout<<"\n";
    return 0;   //:D
}


