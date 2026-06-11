#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	int N, M; cin >> N >> M;
    vector<pair<int, int>> student(N), check(M);
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        student[i].first = a;
        student[i].second = b;
    }
    for(int i = 0; i < M; i++) {
        int c, d; cin >> c >> d;
        check[i].first = c;
        check[i].second = d;
    }
    for(int i = 0; i < N; i++) {
        int m = inf;
        int move = -1;
        for(int j = 0; j < M; j++) {
            int mdist = abs(student[i].first - check[j].first) + abs(student[i].second - check[j].second);
            if(mdist < m) {
                move = j + 1;
                m = mdist;
            }
        }
        cout << move << endl;
    }
	return 0;
}