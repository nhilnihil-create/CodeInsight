#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)
#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define op(i) cout << (i) << endl;
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int infi = 2147483600;
const ll infl = 1e17;



int main()
{
    ll w, h;
    cin >> w >> h;
    vector<ll> p(w), q(h);
    rep(i, w) cin >> p[i];
    rep(i, h) cin >> q[i];
    sort(all(p));
    sort(all(q));
    ll noww = w+1, nowh = h+1;
    ll cnt = w + h;
    ll pidx = 0, qidx = 0;
    ll ans = 0;
    while (cnt>0){
        if (pidx==w){
            ans += noww * q[qidx];
            qidx++;
            cnt--;
            nowh--;
        }
        else if (qidx==h){
            ans += nowh * p[pidx];
            pidx++;
            cnt--;
            noww--;
        }
        else {
            if (p[pidx]<q[qidx]){
                ans += nowh * p[pidx];
                pidx++;
                cnt--;
                noww--;
            }
            else if (p[pidx]>q[qidx]){
                ans += noww * q[qidx];
                qidx++;
                cnt--;
                nowh--;
            }
            else{
                if (noww<=nowh){
                    ans += noww * q[qidx];
                    qidx++;
                    cnt--;
                    nowh--;
                }
                else
                {
                    ans += nowh * p[pidx];
                    pidx++;
                    cnt--;
                    noww--;
                }
            }
        }

    }
    cout << ans << endl;
}
