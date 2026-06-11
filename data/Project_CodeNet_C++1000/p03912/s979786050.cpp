#include<iostream>
#include <list>
#include<stack>
#include<queue>
#include <vector>
#include <set>
#include <map>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include <functional>
#include"time.h"
using namespace std;

#define FOR(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define LL long long
#define CLR(a) memset((a),0,sizeof(a))
#define SZ(x) (int((x).size()))
#define dump(x)  cerr << #x << " = " << (x) << endl
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<<str<<endl
const int INF = (1 << 30);

//毎回変える定数
#define N_MAX 200


//問題文のとおりの変数
int N, M;
//vector<int> X;

//オリジナル変数
vector<vector<int>> kind;//種類分け(第1-indexがmod M)
int ans = 0;

//サブ関数
//入力
void input() {
	cin >> N >> M;
	REP(i, M)kind.push_back(vector<int>());

	REP(i, N) {
		int tmp;
		cin >> tmp;
		kind[tmp%M].push_back(tmp);
	}
}

//計算
int matching(vector<int> little, vector<int> big) {
	if (little.size() > big.size()) {
		vector<int> tmp = little;
		little = big;
		big = tmp;
	}
	int pair = little.size();
	int bigPair = 0;
	int maxBigPair = (big.size() - little.size()) / 2;

	sort(big.begin(), big.end());
	REP(i, (int)big.size() - 1) {
		if (big[i] == big[i+1]) {
			bigPair++;
			i++;
		}
	}

	return pair + min(maxBigPair, bigPair);
}

void calc() {
	int small = 1;
	int large;
	while (small < (large = M - small)) {
		if (kind[small].size() < kind[large].size()) {
			ans += matching(kind[small], kind[large]);
		}
		else {
			ans += matching(kind[large], kind[small]);
		}
		small++;
	}

	//例外処理
	ans += (int)kind[0].size() / 2;
	if (M % 2 == 0)ans += (int)kind[M / 2].size() / 2;
}

//出力
void output() {
	cout << ans << endl;
}

//デバッグ
void debug() {
	cin >> N;
}

//メイン関数
int main() {

	input();
	calc();
	output();
	//debug();

	return 0;
}