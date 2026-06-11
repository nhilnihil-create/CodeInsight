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

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int now = 0;
    vector<int >v;
    for(int i = 1; now < N; i++) {
        now += i;
        v.push_back(i);
    }
    for(int i = 0; i < v.size(); i++) {
        if(now - v[i] == N) {
            now -= v[i];
            v.erase(v.begin() + i);
        }
    }
    for(int i = 0; i < v.size(); i++) cout << v[i] << endl;
    return 0;
}
