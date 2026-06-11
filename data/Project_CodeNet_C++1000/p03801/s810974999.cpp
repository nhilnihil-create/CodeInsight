//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<ll, int>;
using vs = vector<string>;
using vi = vector<ll>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    cin >> n;
    vector<P> a(n);
    ll sum = 0LL;
    vi uu(n);
    set<ll> se;
    rep(i, n) {
        ll aa;
        cin >> aa;
        sum += aa;
        a[i] = P(aa, i);
        set<ll>::iterator k = se.upper_bound(aa);
        if(k == se.begin()) {
            uu[i] = 838247;
        } else {
            uu[i] = *prev(k);
        }
        se.insert(aa);
    }


    sort(all(a));
    ll sum2=0LL;
    vi x(n);
    while(true) {
        vector<P>::iterator itr = lower_bound(all(a), P(a[a.size()-1].first, 0));
        if((*itr).second == 0) {
            x[0] = sum-sum2;
            break;
        }
        int hhhh = (*itr).second;
        ll summ = 0;
        vector<P>::iterator itr2 = lower_bound(all(a), P(uu[(*itr).second], 0));
        while(true) {
            ll num = a.end() - itr;

            x[hhhh] += (n-(itr-a.begin()))*((*itr).first - (*(itr-1)).first);
            sum2 += (n-(itr-a.begin()))*((*itr).first - (*(itr-1)).first);
            rep(i, num) {
                a.pop_back();
            }
            if((*itr2).first == a[a.size()-1].first) {
                break;
            }
            itr = lower_bound(all(a), P(a[a.size()-1].first, 0));
        }
        //cout << summ << endl;
    }
    //cout << sum << endl;
    //cout << sum2 << endl;
    
    rep(i, n) {
        cout << x[i] << '\n';
    }
}