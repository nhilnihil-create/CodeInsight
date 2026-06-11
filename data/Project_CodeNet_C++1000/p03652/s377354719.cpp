#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> sp(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> sp[i][j];
        }
    }
    int ans = N;
    vector<bool> use(M+1, true);
    for (int i = 0; i < M-1; i++) {
        vector<int> cnt(M+1, 0);
        for (int j = 0; j < N; j++) {
            int pos = 0;
            while (!use[sp[j][pos]]) pos++;
            cnt[sp[j][pos]]++;
            //cout << sp[j][pos];
        }
        cout << endl;
        int m = 0;
        int m_sp;
        for (int j = 1; j <= M; j++) {
            if (m < cnt[j]) {
                m = cnt[j];
                m_sp = j;
            }
        }
        ans = min(ans, m);
        //cout << m_sp << endl;
        use[m_sp] = false;
    }
    cout << ans << endl;
    return 0;
}