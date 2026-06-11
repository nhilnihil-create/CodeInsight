#include <iostream>
#include <vector>
using namespace std;

int N, M;
int A[100005], B[100005];

vector<int> Adj[100005];

int check[100005];

vector<int> V1;

void DFS(int K) {
	//cout << "K= " << K << endl;
	V1.push_back(K); check[K]=1;

	for (int h = 0; h < (int)Adj[K].size(); h++) {
		int W = Adj[K][h];
		if (check[W] == 0) { DFS(W); break; }
	}

}

int main(void) {

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i]; 
		Adj[A[i]].push_back(B[i]);
		Adj[B[i]].push_back(A[i]);
	}

	vector<int> ans;

	check[1] = 1;
	int count = 0;

	//=====================
	int W = Adj[1][0];
	DFS(W);
	int J = V1.size();
	for (int j = J - 1; j >= 0; j--) {
		ans.push_back(V1[j]);
	}
	//==================

	ans.push_back(1);

	//=============
	for (int u = 1; u < (int)Adj[1].size(); u++) {
		V1.clear();
		int W = Adj[1][u];
		if (check[W] == 0) {
			DFS(W);

			for (int j = 0; j < (int)V1.size(); j++) {
				ans.push_back(V1[j]);
			}
			break;
		}
		
	}


	cout << ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++) {
		if (i != 0) { cout << " "; }
		cout << ans[i];
	}cout << endl;
	
	//system("pause");
	return 0;
}