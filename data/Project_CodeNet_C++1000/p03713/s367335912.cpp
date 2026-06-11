#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    ll H, W;
    cin >> H >> W;

    ll res = 1e18;
    for (ll h = 1; h < H; h++) {
        ll h1 = (H - h) / 2; 
        ll h2 = H - h - h1;
        vector<ll> a = {
            h * W,
            h1 * W,
            h2 * W
        }; 
        if (*min_element(all(a)) <= 0) {
            continue;
        }
        res = min(res, *max_element(all(a)) - *min_element(all(a)));
    
    }

    for (ll h = 1; h < H; h++) {
        ll w1 = W / 2; 
        ll w2 = W - w1;
        ll h1 = H - h;
        vector<ll> a = {
            h * W,
            h1 * w1,
            h1 * w2
        }; 
        if (*min_element(all(a)) <= 0) {
            continue;
        }
        res = min(res, *max_element(all(a)) - *min_element(all(a)));

    }

    //
    swap(W, H);
    for (ll h = 1; h < H; h++) {
        ll h1 = (H - h) / 2; 
        ll h2 = H - h - h1;
        vector<ll> a = {
            h * W,
            h1 * W,
            h2 * W
        }; 
        if (*min_element(all(a)) <= 0) {
            continue;
        }
        res = min(res, *max_element(all(a)) - *min_element(all(a)));
    }

    for (ll h = 1; h < H; h++) {
        ll w1 = W / 2; 
        ll w2 = W - w1;
        ll h1 = H - h;
        vector<ll> a = {
            h * W,
            h1 * w1,
            h1 * w2
        }; 
        if (*min_element(all(a)) <= 0) {
            continue;
        }
        res = min(res, *max_element(all(a)) - *min_element(all(a)));
    }

    put(res);

    return 0;
}