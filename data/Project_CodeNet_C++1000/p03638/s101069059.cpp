#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;
static long long INF = (1LL<<62);
using LLPair = pair<LL, LL>;

int main(int argc, char* argv[]){
	int H, W, N;
	vector<int> A;
	vector<int> B;

	cin >> H >> W;
	cin >> N;
	for(int i=0; i<N; i++){
		int a; cin >> a;
		A.push_back(a);
	}

	for(int i=0; i<A.size(); i++){
		for(int j=0; j<A[i]; j++){
			B.push_back(i+1);
		}
	}

	int dir = 1;
	for(int i=0; i<H; i++){
		vector<string> S;
		for(int j=0; j<W; j++){
			int c = B[B.size()-1]; B.pop_back();
			string s = to_string(c);
			S.push_back(s);
			if(j != W-1){
				S.push_back(" ");
			}
		}
		if(dir == -1){
			reverse(S.begin(), S.end());
		}
		for(int i=0; i<S.size(); i++){
			printf("%s", S[i].c_str());
		}
		printf("\n");
		dir *= (-1);
	}
	return 0;
}