#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vector2d = vector<vector<T>>;
template<class S, class T> void map_init(map<S, T> &m, S k, T v){if(!m.count(k)) m[k] = v;}
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> m(N, 0);
    for(auto &x : a) cin >> x;
    int d = *max_element(WHOLE(a)) + 1;
    bool ans = true;
    for(int i = 0; i < N; i++) {
        m[a[i]]++;
    }
    for(int i = 0; i < d; i++) {
        if(i < d / 2) {
            ans &= m[i] == 0;
        } else if(i == d / 2) {
            if(d % 2 == 0) {
                ans &= m[i] == 2;
            } else {
                ans &= m[i] == 1;
            }
        } else if(i > d / 2) {
            ans &= m[i] >= 2;
        }
    }
    cout << (ans ? "Possible" : "Impossible") << endl;
    return 0;
}