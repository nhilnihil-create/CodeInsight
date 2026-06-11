#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)
typedef long long ll;

using namespace std;

template <typename T> void output(T, int);
int gcd(int a, int b);
void prime_map(map<ll, ll> &, ll);

int main() {
    // source
    int N, W;
    cin >> N >> W;
    int w[N], v[N];
    int w_min = pow(10, 9);
    rep(i, N) {
        cin >> w[i] >> v[i];
        w_min = min(w_min, w[i]);
    }

    vector<vector<int>> vec(4);
    rep(i, N) { vec[w[i] - w_min].push_back(v[i]); }
    sort(vec[0].rbegin(), vec[0].rend());
    sort(vec[1].rbegin(), vec[1].rend());
    sort(vec[2].rbegin(), vec[2].rend());
    sort(vec[3].rbegin(), vec[3].rend());

    vector<ll> sum[4];
    rep(l0, 4) {
        ll temp = 0;
        sum[l0].push_back(temp);
        rep(l1, vec[l0].size()) {
            temp += vec[l0][l1];
            sum[l0].push_back(temp);
            // cout << temp << ",";
        }
        // cout << endl;
    }

    ll ans = 0;
    rep(l0, sum[0].size()) {
        rep(l1, sum[1].size()) {
            rep(l2, sum[2].size()) {
                rep(l3, sum[3].size()) {
                    ll weight = 0;
                    weight += l0 * w_min;
                    weight += l1 * (w_min + 1);
                    weight += l2 * (w_min + 2);
                    weight += l3 * (w_min + 3);

                    if (weight > W) {
                        continue;
                    }

                    ll v_now =
                        sum[0][l0] + sum[1][l1] + sum[2][l2] + sum[3][l3];
                    // cout << l0 << "," << l1 << "," << l2 << "," << l3 <<
                    // endl;
                    ans = max(ans, v_now);
                }
            }
        }
    }

    cout << ans << endl;
}
template <typename T> void output(T a, int precision) {
    if (precision > 0) {
        cout << setprecision(precision) << a << "\n";
    } else {
        cout << a << "\n";
    }
}

template <typename T> T min(T a, T b) {

    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void prime_map(map<ll, ll> &m, ll num) {
    ll cache = num;
    repd(i, 2, sqrt(num) + 2) {
        if (num % i == 0) {
            if (m[i] == 0) {
                m[i] = 1;
            } else {
                m[i]++;
            }

            num /= i;
            break;
        }
    }

    if (cache == num) {
        if (m[num] == 0) {
            m[num] = 1;
        } else {
            m[num]++;
        }
        return;
    } else {
        prime_map(m, num);
    }
}
