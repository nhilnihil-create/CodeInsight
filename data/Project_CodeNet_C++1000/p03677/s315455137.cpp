#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)1e5 + 50;
const ll INF = (ll)1e18;

vector<int> in[N], out[N];
int n, m;
P p[N];

int get_len(int i) {
    int res = p[i].second - p[i].first;
    if(res < 0) res += m;
    return res;
}

int main() {
    cin >> n >> m;
    cin >> p[0].first;
    for(int i = 0; i < n - 1; i++) {
        cin >> p[i].second;
        p[i+1].first = p[i].second;
    }
    n--;

    int cnt = 0;
    ll sum = 0, res = INF;
    for(int i = 0; i < n; i++) {
//        cout << p[i].first << "," << p[i].second << endl;
        int f1 = p[i].first;
        if(f1 > m) f1 -= m;
        in[f1].push_back(i);
        out[p[i].second].push_back(i);
        if(p[i].first > p[i].second) {
            cnt++;
            sum += p[i].second - 1;
        }
        else {
            sum += p[i].second - p[i].first;
        }
    }
//    cout << sum << endl;
    for(int i = 1; i <= m; i++) {
        res = min(res, sum + cnt);
//        cout << i << ", " << sum << " " << cnt << endl;
        cnt += in[i].size();
        cnt -= out[i].size();
        for(auto x : out[i]) {
            sum += get_len(x);
//            cout << get_len(x) - 1 << endl;
        }
        sum -= cnt;
    }
    cout << res << endl;

}