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
    // T, S, Z はカドを埋められないので、居るだけ
    i64 I, O, T, J, L, S, Z;
    cin >> I >> O >> T >> J >> L >> S >> Z;
    i64 ans = 0;

    ans += O;

    // 「問」型を作るかどうか
    if(I > 0 && J > 0 && L > 0 && I % 2 + J % 2 + L % 2 > 1) {
        ans += 3;
        I--, J--, L--;
    }
    ans += (J / 2 + L / 2 + I / 2) * 2;

    cout << ans << endl;

    return 0;
}