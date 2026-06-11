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
const int INF = 1000000007;

//毎回変える定数
#define N_MAX 200


//問題文のとおりの変数
int N;

//オリジナル変数
int s;
vector<vector<LL>> dp;

//入力
void input() {
	cin >> N;
	string tmp;
	cin >> tmp;
	s = tmp.size();

	REP(i, N+1) {
		dp.push_back(vector<LL>(N+1));
	}
	dp[0][0] = 1;
}

void calc() {
	REP(i, N){
		REP(j, N) {
			//バックスペース
			if (j == 0) {
				dp[i + 1][0] += dp[i][j];
				dp[i + 1][0] %= INF;
			}
			else {
				dp[i + 1][j - 1] += dp[i][j] * 2;
				dp[i + 1][j - 1] %= INF;
			}
			//挿入
			dp[i + 1][j + 1] += dp[i][j];
			dp[i + 1][j + 1] %= INF;
		}
		//cout << i << endl;
	}
}



void output() {
	cout << dp[N][s] << endl;
}

void debug() {
	/*
	REP(i, N + 1) {
		REP(j, N) {
			cout << dp[i][j] << "  ";
		}
		cout << endl;
	}*/
	cin >> N;
}


//メイン関数
int main() {
	
	input();
	calc();
	output();
	return 0;
}



