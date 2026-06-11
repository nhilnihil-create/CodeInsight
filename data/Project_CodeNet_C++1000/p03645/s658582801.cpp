#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<int, pair<int, int> > p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > s(N);

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        s[a].push_back(b);
        s[b].push_back(a);
    }

    bool checker = false;

    for(int i = 0; i < s[0].size(); i++) {
        for(int j = 0; j < s[s[0][i]].size(); j++) {
            if(s[s[0][i]][j] == N - 1) {
                checker = true;
                break;
            }
        }
        if(checker) break;
    }

    if(checker) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}