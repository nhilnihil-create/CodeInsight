//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

void dout() { cerr << '\n'; }

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << " " << H;
    dout(T...);
}

#ifdef LOCAL
    #define dbg(...) cerr << #__VA_ARGS__, dout(__VA_ARGS__)
#else
    #define dbg(...) ;
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;

const int N = 200007, alph = 26;
int n, last[alph][N], suf[N];
string s;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> s;
    n = s.size();
    memset(& last, -1, sizeof(last));

    int mask = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < alph; j++) {
            last[j][i] = last[j][i + 1];
        }
        int ch = (s[i - 1] - 'a');
        last[ch][i] = i;
        suf[i] = suf[i + 1];

        mask |= (1 << ch);
        if (mask == (1 << alph) - 1) {
            mask = 0;
            suf[i]++;
        }
    }
    int len = suf[1] + 1, cur = 1;
    string ans = "";
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < alph; j++) {
            if (last[j][cur] == -1) {
                if (len == i) {
                    ans += char('a' + j);
                    break;
                }
            }
            if (len - i > suf[last[j][cur] + 1]) {
                cur = last[j][cur] + 1;
                ans += char('a' + j);
                break;
            }
        }
    }
    cout << ans;
}
