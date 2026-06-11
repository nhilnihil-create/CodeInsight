#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

/*
#define cin ifs
#define cout ofs
ifstream ifs("in.txt");
ofstream ofs("out.txt");
//*/

int N;

signed main() {
    cin >> N;
    bitset<50> bs(N);
    stack<int> stk;
    int max_bit = 0;
    for (int i = 49; i >= 0; i--) {
        if (bs[i]) {
            stk.push(i);
            max_bit = max(max_bit, i);
        }
    }
    cout << stk.size() + max_bit + 100 << endl;
    cout << 100;
    for (int i = 0;; i++) {
        if (stk.top() == i) {
            if (stk.size() != 1) {
                cout << " " << stk.size() + max_bit - 1;
            }
            stk.pop();
        }
        if (stk.empty()) {
            break;
        }
        cout << " " << i + 1;
    }
    for (int i = 1; i <= 100; i++) {
        cout << " " << i;
    }
    cout << endl;
    return 0;
}