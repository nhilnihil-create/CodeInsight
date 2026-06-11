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
int n, suf[N];
vector <int> vec[alph];
string s;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> s;
    n = s.size();

    int mask = 0;
    for (int i = n; i >= 1; i--) {
        int ch = (s[i - 1] - 'a');
        vec[ch].pb(i);

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
            if (vec[j].empty()) {
                if (len == i) {
                    ans += char('a' + j);
                    break;
                }
            }
            int nxt = vec[j].back() + 1;
            if (len - i > suf[nxt]) {
                for (int k = cur; k < nxt; k++) {
                    int ch = (s[k - 1] - 'a');
                    vec[ch].ppb();
                }
                cur = nxt;
                ans += char('a' + j);
                break;
            }
        }
    }
    cout << ans;
}
