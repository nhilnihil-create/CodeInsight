#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#include<set>


//---------------------------------------------
 


int main (void)
{
    ll n,c,k;
    cin>>n>>c>>k;

    vector<ll> t(n);
    rep(i,n) cin>>t[i];


    sort(t.begin(),t.end());

    ll bus =0;
    ll firsttime =-1;
    ll pop = 0;
    for(int i=0;i<n;i++)
    {
        if(pop==0)
        {
            firsttime = t[i];
            pop =1;
        }
        else
        {
            if(t[i]-firsttime<=k&&pop+1<=c)
            {
                pop++;
            }

            else
            {
                bus ++;
                pop=1;
                firsttime = t[i];
            }
        }

    }

    if(pop>0) bus ++;
    cout<<bus<<endl;
}