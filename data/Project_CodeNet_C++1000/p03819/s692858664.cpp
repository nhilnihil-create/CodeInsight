#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 3e5 + 7, MAXM = 1e5 + 7;
int bit[MAXM];

void upd(int i, int x)
{
    for (; i < MAXM; i += i & (-i)) bit[i] += x;
}

int get(int i)
{
    int ans = 0;
    for (; i > 0; i -= i & (-i)) ans += bit[i];
    return ans;
}

int N, M;
vector<int> add[MAXM], rem[MAXM];
int ans[MAXM];
vector<int> factors[MAXM];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;

    for (int d = 1; d <= M; ++d) {
        for (int i = d; i <= M; i += d) {
            factors[i].push_back(d);
        }
    }

    for (int i = 0; i < N; ++i) {
        int l, r;
        cin >> l >> r;
        add[l].push_back(l);
        rem[r].push_back(l);
    }

    for (int i = 1; i <= M; ++i) {
        for (int x : add[i]) upd(x, 1);
        for (int x : factors[i]) {
            ans[x] += get(i) - get(i - x);
        }
        for (int x : rem[i]) upd(x, -1);
    }

    for (int i = 1; i <= M; ++i) cout << ans[i] << '\n';
}
