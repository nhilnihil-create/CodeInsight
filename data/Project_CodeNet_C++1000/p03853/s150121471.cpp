#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N,M;

	cin >> N >> M;

	char in[N+1][M+1];

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin >> in[i+1][j+1];

	char out[2*N + 1][M + 1];

	for(int i = 1; i <= 2*N; i++){
		for(int j = 1; j <= M; j++) out[i][j] = in[(i + 1)/2][j];
	}

	for(int i = 1; i <= 2*N; i++)
		for(int j = 1; j <= M; j++)
			cout << out[i][j] << (j == M ? "\n" : "");

	return 0;
}
