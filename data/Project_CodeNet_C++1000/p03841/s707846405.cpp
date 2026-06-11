//実験ゲー
//pos[i][j] = 値i(>=0)の左からj(>=0)番目の位置(0-indexed)とおき、posの復元順序を「左下,対角→対角,右上」とすればよい。
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int n;
int x[500];
P order[500];
int query[250000];
vector<int> pos[500];
int ans[250000];

int main() {
	int i, j;
	
	cin >> n;
	for (i = 0; i < n * n; i++) query[i] = -1;
	for (i = 0; i < n; i++) { cin >> x[i]; x[i]--; order[i] = P(x[i], i); query[x[i]] = i; }
	sort(order, order + n);
	
	int t = 0;
	
	//1. まだ対角成分の左隣が埋まっていない行iのうち、x_iが最小の行を選択し、対角成分の左隣まで埋める
	//2. 1の過程で、対角成分を埋めるタイミングがあれば埋める。ここで埋められなければNO.
	for (i = 0; i < n; i++) {
		int row = order[i].second;
		for (j = 0; j < row; t++) {
			if (query[t] >= 0) {
				if (pos[query[t]].size() != query[t]) { cout << "No" << endl; return 0; }
				pos[query[t]].push_back(t);
			}
			else {
				pos[row].push_back(t);
				j++;
			}
		}
	}
	
	//3. 対角成分が埋まっているが一番右までは埋まっていない行iを適当に1つ選び、一番右まで埋める。埋めた要素数 < n * nなのにiを選べなければNO.
	//4. 3の過程で、対角成分を埋めるタイミングがあれば埋める。  (↑行iを選ぶ前に4を行うケースもあるので、注意）
	while (t < n * n) {
		if (query[t] >= 0) {
			if (pos[query[t]].size() != query[t]) { cout << "No" << endl; return 0; }	//ここのチェックいらないかも
			pos[query[t]].push_back(t);
			t++;
			continue;
		}
		
		for (i = 0; i < n; i++) if (i + 1 <= pos[i].size() && pos[i].size() < n) break;
		if (i == n) { cout << "No" << endl; return 0; }
		
		while (pos[i].size() < n) {
			if (query[t] >= 0) {
				if (pos[query[t]].size() != query[t]) { cout << "No" << endl; return 0; } //ここのチェックいらないかも
				pos[query[t]].push_back(t);
			}
			else {
				pos[i].push_back(t);
			}
			t++;
		}
	}
	
	//構成完了
	for (i = 0; i < n; i++) for (j = 0; j < pos[i].size(); j++) ans[pos[i][j]] = i;
	cout << "Yes" << endl;
	for (i = 0; i < n * n; i++) {
		cout << ans[i] + 1;
		if (i + 1 < n * n) cout << " ";
	}
	cout << endl;
	return 0;
}