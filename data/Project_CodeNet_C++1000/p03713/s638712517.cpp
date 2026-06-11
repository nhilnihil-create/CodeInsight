#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    ll h, w; cin >> h >> w;

    if(h%3==0 || w%3==0){
        cout << 0 << endl;
        return 0;
    }

    dump(h);
    ll ht = h/3LL;
    ll ht1 = (h+2)/3LL;

    ll tmp = max(w*ht, (h-ht)*((w+1)/2LL)) - min(w*ht, (h-ht)*(w/2LL));
    dump(tmp);
    tmp = min(tmp, max(w*ht1, (h-ht1)*((w+1)/2LL)) - min(w*ht1, (h-ht1)*(w/2LL)));
    dump(tmp);

    ll wt = w/3LL;
    ll wt1 = (w+2)/3LL;

    ll tmp2 = max(h*wt, (w-wt)*((h+1)/2LL)) - min(h*wt, (w-wt)*(h/2LL));
    dump(tmp2);
    tmp2 = min(tmp2, max(h*wt1, (w-wt1)*((h+1)/2LL)) - min(h*wt1, (w-wt1)*(h/2LL)));
    dump(tmp2);

    ll ans = min(tmp, tmp2);
    ans = min(w, min(h, ans));
    cout << ans << endl;

    return 0;
}
