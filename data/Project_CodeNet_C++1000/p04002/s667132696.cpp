#include <bits/stdc++.h>
using namespace std;

#define    ll     long long int

int dx[] = { +1, -1, 0, 0 };
int dy[] = { 0, 0, +1, -1 };

const int N = 1e9 + 9;
ll h, w;
set< pair<int, int> > st, bl;
int n;
vector< pair<int, int> > v;
ll ans[11];
ll total = 0;

int isvalid(int x, int y)
{
     if (x >= 1 && y >= 1 && x + 2 <= h && y + 2 <= w)
        return 1;
     return 0;
}

void kaj(int x, int y)
{
    if (isvalid(x, y) == 0) {
        return ;
    }
    int c = 0, i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (bl.find(make_pair(i + x, j + y)) != bl.end()) {
                c++;
            }
        }
    }
    st.insert(make_pair(x, y));
    ans[c]++;
    total++;
}

void solve(int x, int y)
{
    int c = 0, i, j, k, tx, ty;
    kaj(x, y);
    if (st.find(make_pair(x, y - 1)) == st.end()) {
        kaj(x, y - 1);
    }
    if (st.find(make_pair(x, y - 2)) == st.end()) {
        kaj(x, y - 2);
    }
    if (st.find(make_pair(x - 1, y)) == st.end()) {
        kaj(x - 1, y);
    }
    if (st.find(make_pair(x - 1, y - 1)) == st.end()) {
        kaj(x - 1, y - 1);
    }
    if (st.find(make_pair(x - 1, y - 2)) == st.end()) {
        kaj(x - 1, y - 2);
    }
    if (st.find(make_pair(x - 2, y)) == st.end()) {
        kaj(x - 2, y);
    }
    if (st.find(make_pair(x - 2, y - 1)) == st.end()) {
        kaj(x - 2, y - 1);
    }
    if (st.find(make_pair(x - 2, y - 2)) == st.end()) {
        kaj(x - 2, y - 2);
    }
}

int main( )
{
    cin >> h >> w >> n;
    ll i, x, y;
    for (i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
        bl.insert(make_pair(x, y));
    }
    sort(v.begin(), v.end());
    for (i = 0; i < n; i++) {
        solve(v[i].first, v[i].second);
    }
    cout << ((h - 2) * (w - 2) - total) << '\n';
    for (i = 1; i <= 9; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
