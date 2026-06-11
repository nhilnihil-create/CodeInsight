#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
#include<stack>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#include<set>
int main(void)
{
    ll n,m;
    cin>>n>>m;
    vector<bool> prob(n+5);
    vector<ll> num(n+5);

    rep(i,n+2) 
    {
        prob[i]=false;
        num[i] =1;
    }
    prob[1]=true;

    rep(i,m)
    {
        ll a;
        ll b;
        cin>>a>>b;

        if(prob[a]==true) prob[b] = true;

        num[a] --;
        num[b] ++;
        if(num[a]==0) prob[a] = false;
    }
    ll ans = 0;


    for(ll q=1;q<=n;q++)
    {
        if(prob[q]==true) ans ++;
    }

    cout << ans << endl;
}