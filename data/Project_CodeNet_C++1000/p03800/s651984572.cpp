#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class S, class T> void map_init(map<S, T> &m, S k, T v){if(!m.count(k)) m[k] = v;}
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    vector<int> S;
    for(auto x : s) S.push_back(x == 'o');
    vector<int> ans;
    for(int a0 = 0; a0 < 2; a0++) {
        for(int a1 = 0; a1 < 2; a1++) {
            int x = a0, y = a1, z = 0;
            ans.push_back(x);
            ans.push_back(y);
            for(int i = 1; i < N - 1; i++) {
                z = x ^ y ^ S[i];
                x = y, y = z;
                ans.push_back(z);
            }
            if( (ans[0] ^ ans[N - 1] ^ ans[N - 2] ^ S[N - 1] == 0) &&
                (ans[1] ^ ans[0] ^ ans[N - 1] ^ S[0] == 0)) {
                for(auto x : ans) cout << (x ? 'S' : 'W');
                cout << endl;
                return 0;
            }
            ans.clear();
        }
    }
    cout << -1 << endl;
    return 0;
}