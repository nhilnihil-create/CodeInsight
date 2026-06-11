#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
int main() {
    int N;
    cin >> N;
    map<int, int> m;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if(!m.count(a)) m[a] = 0;
        m[a]++;
    }
    if(m.size() == 2) {
        int a, b, x, y;
        auto i = m.begin();
        tie(x, a) = *i;
        i++;
        tie(y, b) = *i;
        if(x > y) {
            swap(x, y);
            swap(a, b);
        }
        if(y - x == 1 && 2 * a + b >= 2 * y && y > a) {
            cout << "Yes" << endl;
            return 0;
        }
    } else if(m.size() == 1) {
        int a, x;
        tie(x, a) = *m.begin();
        if(x == a - 1 || a >= 2 * x) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}