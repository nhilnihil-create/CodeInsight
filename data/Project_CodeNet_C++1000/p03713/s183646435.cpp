#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll INF = 1e10;

ll ans = INF;
 
void calc(ll s1, ll s2, ll s3) {

    if(s1 > 0 && s2 > 0 && s3 > 0) {

        ll maxS = max({s1, s2, s3});
        ll minS = min({s1, s2, s3});

        ll now = maxS - minS;

        ans = min(ans, now);
    }
}

int main() {
    ll h, w, s1, s2, s3, a, b;
    cin >> h >> w;

    rep(i, h) {

        a = (h-i)/2;
        b = h-(i+a);

        s1 = i*w;
        s2 = a*w;
        s3 = b*w;

        calc(s1, s2, s3);
    }

    rep(i, h) {
        
        a = w/2;
        b = w-a;

        s1 = i*w;
        s2 = a*(h-i);
        s3 = b*(h-i);

        calc(s1, s2, s3);
    }

    rep(j, w) {

        a = (w-j)/2;
        b = w-(j+a);

        s1 = j*h;
        s2 = a*h;
        s3 = b*h;

        calc(s1, s2, s3);
    }

    rep(j, w) {

        a = h/2;
        b = h-a;

        s1 = j*h;
        s2 = a*(w-j);
        s3 = b*(w-j);

        calc(s1, s2, s3);
    }

    cout << ans << endl;
    return 0;
}