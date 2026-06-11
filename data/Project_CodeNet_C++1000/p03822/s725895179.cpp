#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int test[12345678];
signed main() {
	int n, a, res = 0, ok = 0; cin >> n;
    vector<vector<int>> kariG(n + 1), cost(123456), ans(123456);
    vector<int> G(n + 1), kari(n + 1); for (int h = 2; h <= n; h++) {
        cin >> a; G[h] = a; kari[a]++; kariG[a].push_back(h);
	} queue<int> QUE; queue<int> CNT;
    for (int i = 0; i < kariG[1].size(); i++) {
        QUE.push(kariG[1][i]); CNT.push(2); 
        if (kariG[kariG[1][i]].size() == 0) {
            cost[2].push_back(kariG[1][i]);
        } res = max(res, (long long)2);
    }
    while (QUE.size()) {
        for (int i = 0; i < kariG[QUE.front()].size(); i++) {
            QUE.push(kariG[QUE.front()][i]); CNT.push(CNT.front() + 1);
            if (kariG[kariG[QUE.front()][i]].size() == 0) {
                cost[CNT.front() + 1].push_back(kariG[QUE.front()][i]);
            } res = max(res, CNT.front() + 1);
        } QUE.pop(); CNT.pop();
    }
    for (int h = res; h >= 0; h--) {
        for (int i = 0; i < cost[h].size(); i++) { ans[cost[h][i]].push_back(0); }
    }
    for (int h = res; h >= 0; h--) {
        for (int i = 0; i < cost[h].size(); i++) {
            int z = 0; if (cost[h][i] != 1) {
                sort(ans[cost[h][i]].begin(), ans[cost[h][i]].end());
                for (int j = 0; j < ans[cost[h][i]].size(); j++) {
                    ans[cost[h][i]][j] += ans[cost[h][i]].size() - 1 - j;
                    z = max(z, ans[cost[h][i]][j]);
                }
                if (test[G[cost[h][i]]] == 0) { cost[h - 1].push_back(G[cost[h][i]]); }
                test[G[cost[h][i]]]++; ans[G[cost[h][i]]].push_back(z + 1);
            }
        }
    } sort(ans[1].begin(), ans[1].end());
    for (int h = 0; h < ans[1].size(); h++) {
        ans[1][h] += ans[1].size() - h - 1; ok = max(ok, ans[1][h]);
    }
    cout << ok << endl; return 0;
}