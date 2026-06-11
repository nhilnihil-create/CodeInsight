#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using vpii = vector<pair<int, int>>;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep1(i, n) for (int i = 1; i < (int)n; i++)
const ll mod = 1e9 + 7;
const ll inf = 1e12;
const double pi = 3.141592;
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

template <class T>
bool contain(const string &s, const T &v)
{
    return s.find(v) != std::string::npos;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int cnt = 0;
    int ans = n;
    rep(i,n-1){
        ++cnt;
        if(a[i+1] > 2*a[i]){
            ans -= cnt;
            cnt = 0;
        }
        a[i + 1] += a[i];
    }
    cout << ans << "\n";
    return 0;
}