#include <bits/stdc++.h>
#include <cstdio>
#define fastio {ios_base::sync_with_stdio(false); cin.tie(NULL);}
#define nln cout << '\n'
#define ll long long int
#define INF (ll)1e+12
#define MAX 300100
#define mp(i, j) make_pair(i, j)
#define here cout  << "here";nln;
#define mul(a, b, mod) (((a % mod) * (b % mod)) % mod)
#define add(a, b, mod) (((a % mod) + (b % mod)) % mod)
#define inf 100000
#define M 1000000000LL

using namespace std;

ll a[100100];

int main()
{
    ll n, i, ans = 0;

    cin >> n;

    for(i = 0; i < n; i++)cin >> a[i];

    for(i = 0; i < n; i++){
        if(a[i]&1){
            ans += a[i]/2;
            a[i] = 1;
        }
        else if(a[i]){
            ans += (a[i]/2)-1;
            a[i] = 2;
        }
    }

    for(i = 0; i < n-1; i++){
        if(a[i] == 1){
            if(a[i+1]){
                ans++;
                a[i]--;
                a[i+1]--;
            }
        }
    }

    for(i = 0; i< n; i++)if(a[i] == 2LL)ans++;

    cout << ans << endl;
}
