#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

#define MOD 1000000009
typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;


ll lcm(ll a ,ll b)
{
    ll l = __gcd(a,b);
    //cout<<"l"<<" "<<l<<endl;
    return a/l*b;
}

int main()
{
ll n;
cin>>n;

ll ans =1;
for(ll index = 0 ;index < n;index++)
{
    ll c;
    cin>>c;

    ans = lcm(ans,c);
    // cout<<ans<<endl;
}

cout<<ans<<endl;
 return 0;
}
