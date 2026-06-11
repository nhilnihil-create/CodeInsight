#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

int N, M;
vector<vector<int>> E;
bool visited[100000];

int main() {
	cin >> N >> M;
	E.resize(N);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		A--, B--;
		E[A].push_back(B);
		E[B].push_back(A);
	}

	int l = 0, r = E[0][0];//-1になったらループに入ってる判定
	int befl = r, befr = l;
	visited[l] = true, visited[r] = true;
	vector<int> ansl, ansr;
	ansl.push_back(l), ansr.push_back(r);
	while (true) {
		//expends a
		bool updatel = false, updater = false;
		for (int i = 0; i < E[l].size(); i++) {
			if (E[l][i] == befl)continue;
			
			if (!visited[E[l][i]]) {
				visited[E[l][i]] = true;
				ansl.push_back(E[l][i]);
				befl = l;
				l = E[l][i];
				updatel = true;
				break;
			}
		}
		for (int i = 0; i < E[r].size(); i++) {
			if (E[r][i] == befr)continue;

			if (!visited[E[r][i]]) {
				visited[E[r][i]] = true;
				ansr.push_back(E[r][i]);
				befr = r;
				r = E[r][i];
				updater = true;
				break;
			}
		}
		if (!updatel && !updater)break;
	}

	cout << ansl.size() + ansr.size() << endl;
	for (int i = ansl.size() - 1; i >= 0; i--) {
		cout << ansl[i] + 1 << " ";
	}
	for (int i = 0; i < ansr.size(); i++) {
		cout << ansr[i] + 1 << " ";
	}
	cout << endl;
	return 0;
}