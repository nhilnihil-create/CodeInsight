#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll comb[100][100];
ll N = 40;

void initialize() {
    for(int i = 0; i < 100; i++) {
        comb[i][0] = 1;
        for(int j = 1; j < i; j++) {
            comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
        }
        comb[i][i] = 1;
    }
}

ll beki(ll a, ll b) {
    if(b == 0) return 1;
    ll ret = beki(a, b / 2);
    ret = ret * ret;
    if(b & 1) ret *= a;
    return ret;
}

ll f(ll num, ll x, ll y) {
    ll ret = 0;
    for(int j = 1; j <= x; j++) {
        ret += comb[x][j] * comb[num-x][j];
    }
    ret *= y;
    ret += beki(2, y) - 1;
    return ret;
}

ll before[205];
ll afternum[205];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    initialize();
    /*
    for(int i = 0; i <= N / 2; i++) {
        cerr << i << " " << f(i) << endl;
    }
    */
    ll num = 1;
    ll N;
    cin >> N;
    while(beki(2, num) - 1 <= N) num++;
    N -= beki(2, num - 1) - 1;
    int index = 0;
    while(N > 0) {
        index++;
        int now = 0;
        while((now + 1) * 2 <= num && f(num, now + 1, 1) <= N) {
            now++;
        }
        int now2 = 1;
        while(f(num, now, now2 + 1) <= N) now2++;
        N -= f(num, now, now2);
        //cerr << f(num, now, now2) << endl;
        before[index] = now;
        afternum[index] = now2;
    }
    //cerr << "num:" << num << endl;
    //for(int i = 1; i <= index; i++) cerr << i << " " << before[i] << " " << afternum[i] << endl;
    vector<int> ans;
    for(int i = index; i >= 1; i--) {
        for(int j = before[i+1]; j < before[i]; j++) ans.push_back(100);
        ans.push_back(i);
    }
    for(int j = before[1]; j < num; j++) ans.push_back(100);
    for(int i = 1; i <= index; i++) {
        for(int j = 0; j < afternum[i]; j++) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}