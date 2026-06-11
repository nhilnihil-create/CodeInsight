#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main(){ _

	int N,M;
	cin >> N >> M;

	vector<vector<char>> A(N, vector<char>(N));
	vector<vector<char>> B(M, vector<char>(M));
	
	for(auto &x : A)
		for(auto &y : x)
			cin >> y;

	for(auto &x : B)
		for(auto &y : x)
			cin >> y;

	bool ans = 0;
	for(int i = 0; i < N - M + 1; i++){
		for(int j = 0; j < N - M + 1; j++){
			bool ok = 1;
			for(int k = 0; k < M; k++){
				for(int l = 0; l < M; l++){
					ok &= (A[i+k][j+l] == B[k][l]);
				}
			}
			ans |= ok;
		}
	}

	cout << (ans ? "Yes" : "No") << endl;

	return 0;
}
