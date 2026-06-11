#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define pll pair <ll, ll>
#define setbiti(x) __builtin_popcount(x)
#define setbitll(x) __builtin_popcountll(x)
#define gcd(a, b) __gcd(a, b)

#define        MX        200005
ll ara[MX];
int main()
{
    optimize
    ll n;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>ara[i];
    }
    sort(ara, ara+n, greater <ll> ());

    ll ans = 0;
    for(int i = 0; i < n-1; i++){
        if(ara[i] == ara[i+1]){
            if(ans){
                ans *= ara[i];
                break;
            }
            else{
                ans = ara[i];
                i++;
            }
        }
    }
    cout<<ans<<endl;
}
