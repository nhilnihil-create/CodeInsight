#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*string NEXT(string str) {

	int M = str.size();

	if (M == 0) { return "a"; }

	if (str[M - 1] != 'z') {
		str[M - 1]++;
		return str;
	}
	else {
		int q= M - 1;
		while (str[q] == 'z' && q>=0) { q--; }
		cout << "q= " << q << endl;

		if (q < 0) { string ret; for (int i = 1; i <= M + 1; i++) { ret += "a"; } return ret; }

		string ret;
		ret = str.substr(0, q + 1); str[q]++; for (int i = M - 1; i > q; i--) { str += "a"; } return ret;
	}
	return "---";
}*/

string A;
int N;
int dp[200005][30];

int D[200005];

vector<int> V[26];

int main(void) {

	cin >> A;

	N = (int) A.size();
	int q = 0;

	for (int i = N - 1; i >= 0; i--) {
		for (int k = 0; k <= 25; k++) { dp[i][k] = dp[i + 1][k]; }
		 dp[i][A[i] - 'a'] = q+ 1; 

		 int sign = 1;
		 for (int k = 0; k <= 25; k++) { if (dp[i][k] != q + 1) { sign = 0; } }
		 if (sign == 1) { q++; }
	}

	int Km=300005;
	for (int k = 0; k <= 25; k++) { Km = min(Km, dp[0][k]); }
	Km++;
	//cout << "Km= " << Km << endl;

	int K = 300005;

	for (int i = 0; i < N; i++) {
		K = 300005;
		for (int k = 0; k <= 25; k++) {
			K = min(K, dp[i][k]);
		}
		D[i] = K+1;
	}
	D[N] = 1;

	/*for (int i = 0; i <= N; i++) {
		cout << "D[" << i << "]= " << D[i] << endl;
	}*/
	

	for (int i = 0; i < N; i++) {
		char c = A[i];
		V[c - 'a'].push_back(i);
	}
	for (int i = 0; i < 26; i++) { V[i].push_back(N+1); }

	/*for (int i = 0; i < 26; i++) {
		char c = i+'a';
		cout << c ;
		for (int j = 0; j < (int)V[i].size(); j++) {
			cout << " " << V[i][j];
		}cout << endl;
	}*/

	int pos = -1;
	string ans; for (int i = 0; i < Km; i++) {ans += "?";}

	K = Km;
	q = 0;
	int tmp;

	while (pos < N) {
		//cout << "pos= " <<pos<< endl;
		for (int k = 0; k < 26; k++) {
			int cand=lower_bound(V[k].begin(), V[k].end(), pos+1) - V[k].begin();
			//cout << "cand= " << cand;
			tmp = V[k][cand];
			//cout << "  tmp= " << tmp << endl;
			if (D[tmp + 1] == K - 1 || tmp>=N) { pos = tmp;  /*cout << "find: pos= " << pos<<" D[pos+1]= " <<D[pos+1] << endl;*/  ans[q] = (char)k + 'a'; q++; K--; break; }
		}
		
	}

	cout << ans << endl;

	//system("pause");
	return 0;
}