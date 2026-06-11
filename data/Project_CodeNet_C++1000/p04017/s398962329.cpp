#include <bits//stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = n-1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
int n, h, w,l,q,a,b;
int main(void) {
    cin >> n;vector<int> x(n); vector<vector<int>> dob(n+1, vector<int>(22));
    rep(i, n) cin >> x[i];
    cin >> l >> q;
    rep(i, n) dob[i][0] = upper_bound(ALL(x),x[i] + l) - x.begin() - 1;// 1日で行け最大地点
    rep(i, 20) rep(j, n) dob[j][i + 1] = dob[dob[j][i]][i]; // doubling
    rep(i, q) {
        cin >> a >> b; a--; b--;
        if (a > b) swap(a, b);// a> b のとき a<bでも問題ない
        int ans = 0;
        rrep(j, 21) if (dob[a][j] < b) a = dob[a][j], ans += (1 << j);
        ans++; cout << ans << endl;
    }
}