//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    vector <int> right(n, n);
    vector <int> st;
    forn (i, 0, n) {
        while (!st.empty() && a[st.back()] > a[i]) {
            right[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    vector <int> left(n, -1);
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.back()] > a[i]) {
            left[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    cerr << left << "\n" << right << "\n";
    long long ans = 0;
    forn (i, 0, n) {
        int l = i - left[i], r = right[i] - i;
        ans += 1LL * l * r * a[i];
    }
    cout << ans;
    return 0;
}