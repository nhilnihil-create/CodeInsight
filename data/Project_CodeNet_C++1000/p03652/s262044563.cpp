#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int A[300][300];
int cnt[300];
int pointer[300];
bool erased[300];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> A[i][j];
	
	for (int i = 0; i < N; i++)cnt[A[i][0] - 1]++;

	int ans = 114514;
	for (int dec = 0; dec < M; dec++) {
		//一番人の集まるスポーツをピックアップ
		int biggest = 0;
		int sport_id = -1;
		for (int i = 0; i < M; i++) {
			if (biggest < cnt[i])biggest = cnt[i], sport_id = i;
		}

		//この時点での答えを更新
		ans = min(ans, biggest);
		
		//一番集まってるスポーツを消す
		cnt[sport_id] = 0;
		erased[sport_id] = true;
		for (int i = 0; i < N; i++) {
			if (A[i][pointer[i]] == sport_id + 1) {
				pointer[i]++;
				while (pointer[i] < M && erased[A[i][pointer[i]] - 1])
					pointer[i]++;
				if(pointer[i] < M)cnt[A[i][pointer[i]] - 1]++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}