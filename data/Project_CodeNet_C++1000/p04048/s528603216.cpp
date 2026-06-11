#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define testcase int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define allR(x) x.rbegin(),x.rend()

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n,x;
    cin>>n>>x;
    ll k = __gcd(n,x);
    cout<<3*(n-k)<<endl;
    return 0;
}