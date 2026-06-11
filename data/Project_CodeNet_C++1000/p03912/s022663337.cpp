#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

typedef long long ll;

int N, M, X[100000];
int amari[100000];
int cnt[100001];
map<int, int> xc[100000];
int use[100000];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
		cnt[X[i]]++;
		amari[X[i] % M]++;
	}

	for (int i = 0; i < N; i++) {
		xc[X[i] % M][X[i]]++;
	}
	for (int i = 0; i < 100000; i++)use[i] = -1;

	int ans = 0;
	
	for (int i = 0; i < M; i++) {
		if (use[i] == -1) {
		
			if((M % 2 == 0 && i == M / 2) || i == 0)use[i] = amari[i] / 2;
			else use[i] = min(amari[i], amari[M - i]);
			
			ans += use[i];
			use[M - i] = use[i];
			//cout << ans << " " << i << " " << amari[i] << " " << amari[M - i] << endl;
		}
	}
	for (int i = 1; i < M; i++) {
		if (M % 2 == 0 && i == M / 2)continue;
		vector<int> tmp;
		int binaryed = 0;
		for (auto it = xc[i].begin(); it != xc[i].end(); it++) {
			tmp.push_back((*it).second);
			if (tmp.back() % 2 == 1)binaryed++, tmp[tmp.size() - 1]--;
		}
		sort(tmp.begin(), tmp.end());
		
		int pointer = 0;
		use[i] -= binaryed;
		while (pointer < tmp.size() && use[i] > 0) {
			if (use[i] >= tmp[pointer]) {
				use[i] -= tmp[pointer];
				tmp[pointer] = 0;
			}
			else {
				tmp[pointer] -= use[i];
				use[i] = 0;
			}
			pointer++;
		}
		for (int j = 0; j < tmp.size(); j++) {
			ans += (tmp[j] / 2);
		}
	}
	cout << ans << endl;
	return 0;
}