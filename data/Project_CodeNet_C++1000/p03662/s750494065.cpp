#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

vector<int> G[100000];
bool used[100000];
int fc, sc;

void bfs(queue<int> &q, bool f_turn) {
    vector<int> vi;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i : G[v]) if (!used[i]) {
            if (f_turn) fc++;
            else sc++;
            vi.push_back(i);
            used[i] = true;
        }
    }
    for (int i : vi) q.push(i);
}

int main() {
    int N, a, b;
    cin >> N;
    REP(i, N - 1) {
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }

    used[0] = used[N - 1] = true;
    queue<int> fq, sq; fq.push(0); sq.push(N - 1);
    bool f_turn = true;
    while (!fq.empty() || !sq.empty()) {
        if (f_turn) bfs(fq, true);
        else        bfs(sq, false);
        f_turn = !f_turn;
    }

    if (fc > sc) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    return 0;
}