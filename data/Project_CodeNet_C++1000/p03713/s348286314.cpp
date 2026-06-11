#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;

pair<ll,ll> func(ll h, ll w) {
    if (h % 2 == 0 || w % 2 == 0) {
        pair<ll,ll> p(h*w/2, h*w/2);
        return p;
    }

    pair<ll,ll> p(h/2*w, (h/2+1)*w), q(h*(w/2), h*(w/2+1));
    if (p.second - p.first < q.second - q.first)
        return p;
    else 
        return q;
}

int main() {
    ll h, w;    cin >> h >> w;

    ll ans = 1e15;
    for (int i = 1; i < h; i++) {
        pair<ll,ll> p = func(h-i, w);
        ans = min(ans, max(i*w, max(p.first, p.second))-min(i*w, min(p.first, p.second)));
    }
    for (int i = 1; i < w; i++) {
        pair<ll,ll> p = func(h, w-i);
        ans = min(ans, max(h*i, max(p.first, p.second))-min(h*i, min(p.first, p.second)));
    }

    cout << ans << endl;
    return 0;
}