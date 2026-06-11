#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {

	int N, M;
	cin >> N >> M;

	vector<vector<int>> c(M, vector<int>(2));
    rep (i, M) {
        cin >> c.at(i).at(0) >> c.at(i).at(1);
    }


    int a[N + 1] = {0};

    for (int i = 0; i < M; ++i) {
        ++a[c.at(i).at(0)];
        ++a[c.at(i).at(1)];
    }

    for (int i = 1; i <= N; ++i) {
        cout << a[i] << endl;
    }

}
