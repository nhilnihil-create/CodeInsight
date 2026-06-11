#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n, maxa = 0, ans = 0, tb;
    cin >> n;
    for(ll i = 0;i < n;i++){
        ll a, b;
        cin >> a >> b;
        if(maxa < a){
            maxa = a;
            tb = b;
        }
    }

    ans = maxa + tb;
    cout << ans;
    return 0;
}