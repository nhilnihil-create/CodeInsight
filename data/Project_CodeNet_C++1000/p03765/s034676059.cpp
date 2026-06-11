#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define lcm(a, b) (a)/__gcd((a),(b))*(b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1000000007;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<int> Div(int n) {
    vector<int> ret;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);

            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;
    int ssum[SIZE] = {}, tsum[SIZE] = {};
    for(int i = 0; i < s.size(); ++i) {
        int tmp;
        if(s[i] == 'A') {
            tmp = 1;

        } else {
            tmp = 2;

        }
        ssum[i + 1] = ssum[i] + tmp;
    }

    for(int j = 0; j < t.size(); ++j) {
        int tmp;
        if(t[j] == 'A') {
            tmp = 1;

        } else {
            tmp = 2;

        }
        tsum[j + 1] = tsum[j] + tmp;

    }

    int q;
    cin >> q;
    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if((ssum[b] - ssum[a - 1]) % 3 == (tsum[d] - tsum[c - 1]) % 3) {
            cout << "YES";

        } else {
            cout << "NO";

        }
        cout << endl;

    }
    return 0;
}

