#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MN = 300010;

int N, M;
pii seg[MN];
int ans[MN];

struct Fenwick {
    vector<int> tree;
    void init() {
        tree = vector<int>(MN + 1, 0);
    }
    void upd(int idx, int val) {
        for(int i = idx + 1; i <= MN; i += (i & -i)) tree[i] += val;
    }
    int quer(int a) {
        int ret = 0;
        for(int i = a + 1; i >= 1; i -= (i & -i)) ret += tree[i];
        return ret;
    }
} fw;

bool cmp(pii a, pii b) {
    return a.second - a.first < b.second - b.first;
}

int main() {
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++) {
        scanf("%d %d", &seg[i].first, &seg[i].second);
    }

    sort(seg, seg + N, cmp);

    fw.init();
    for(int i = 0; i < N; i++) {
        fw.upd(seg[i].first, 1);
        fw.upd(seg[i].second + 1, -1);
    }
    int pos = N - 1;
    for(int i = M; i >= 1; i--) {
        while(pos >= 0 && seg[pos].second - seg[pos].first >= i) {
            fw.upd(seg[pos].first, -1);
            fw.upd(seg[pos].second + 1, 1);
            pos--;
        }

        ans[i] += N - 1 - pos;
        for(int j = i; j <= M; j += i) {
            ans[i] += fw.quer(j);
        }
    }
    for(int i = 1; i <= M; i++) {
        printf("%d\n", ans[i]);
    }
}
