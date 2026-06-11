#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
#define ll long long
#define MOD 1000000007

vector<int> cap[26];
int G[200010][26];
int rev[200010];

int arr[200010];

int main() {
	for (int i = 0;i < 200010;i++)rev[i] = -1;
	string A;
	cin >> A;
	int N = A.size();
	for (int i = 0;i < N;i++) {
		cap[A[i] - 97].push_back(i);
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < 26;j++) {
			auto it = upper_bound(all(cap[j]), i);
			if (it == cap[j].end()) {
				G[i][j] = 200005;
			}
			else {
				G[i][j] = *it;
			}
		}
	}

	int a, b, c, ord = 0;
	char key;
	string ans = "";
	priority_queue<tuple<int, int, int, char>> Q;//ターン(文字数のマイナス)、行きがけ順(辞書順走査)、位置、最後の文字
	//各頂点にはターンを記録(行きがけ順はやればその通りになるから)
	//更新された時点でそこが最短経路となる
	for (int i = 0;i < 26;i++) {
		if (cap[i].size() == 0) {
			cout << (char)(i + 97) << endl;
			return 0;
		}
		Q.push(make_tuple(0, ord, cap[i][0], i + 97));
		ord--;
		rev[cap[i][0]] = 200006;
	}
	while (!Q.empty()) {
		tie(a, b, c, key) = Q.top();
		Q.pop();
		if (c == 200005) {
			ans += key;
			break;
		}
		for (int i = 0;i < 26;i++) {
			if (rev[G[c][i]] < 0) {
				rev[G[c][i]] = c;
				Q.push(make_tuple(a - 1, ord, G[c][i], i + 97));
				ord--;
			}
		}
	}

	while (rev[c] != 200006) {
		c = rev[c];
		ans += A[c];
	}
	reverse(all(ans));
	cout << ans << endl;
}