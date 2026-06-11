#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i ++)
using namespace std;
using ll = long long;
using PL = pair<ll,ll>;
using P = pair<int,int>;
constexpr int INF = 1000000000;
constexpr long long HINF = 1000000000000000;
constexpr long long MOD = 1000000007;
constexpr double EPS = 1e-4;
constexpr double PI = 3.14159265358979;

int main() {
    int N; cin >> N;
    vector<P> A(N);
    rep(i,N) {
        int a; cin >> a;
        A[i] = P(a,i);
    }
    sort(A.begin(),A.end());

    set<int> st = {-1,N};
    ll ans = 0;
    rep(i,N) {
        int j = A[i].second,a = A[i].first;
        int left = *(--st.lower_bound(j));
        int right = *st.lower_bound(j);
        ans += (ll)a*(right - j)*(j - left);
        st.insert(j);
    }
    cout << ans << endl;
    return 0;
}