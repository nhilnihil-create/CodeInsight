#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define REP(i,n) for (int i = 0; i < n; ++i)
#define REPR(i,n) for (int i = n-1; i >= 0; --i)
#define PB push_back
#define MP make_pair

const int MAX = 3e5;

int N;
bool reserved[MAX];
vii X;
int ans[MAX];

bool solve() {
    int idx = 0;
    REP (i, N) {
        int num = X[i].second, pos = X[i].first;
        REP (n, num-1) {
            while (idx < N*N && ans[idx] != 0) idx++;
            if (idx > pos) return false;
            ans[idx] = num;
        }
    }

    idx = N*N-1;
    REPR (i, N) {
        int num = X[i].second, pos = X[i].first;
        REP (n, N-num) {
            while (idx >= 0 && ans[idx] != 0) idx--;
            if (idx < pos) return false;
            ans[idx] = num;
        }
    }

    return true;
}

int main() {
    cin >> N;
    REP (i, N) {
        int x;
        cin >> x; x--;
        X.PB(MP(x, i+1));
        ans[x] = i+1;
    }
    sort(X.begin(), X.end());
    if (solve()) {
        cout << "Yes" << endl;
        REP (i, N*N-1) cout << ans[i] << " ";
        cout << ans[N*N-1] << endl;
    } else {
        cout << "No" << endl;
    }
}
