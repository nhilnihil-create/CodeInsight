#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;
	int N = (int)s.size();
	// 全部自分がグーを出したとき, 相手のパーの個数をPと置くと-P点に
	// 相手がグーのとき自分がパーだしたら+1点
	// 相手がパーのとき自分がパーだしたら+1点
	// どっちみちパーを出した回数だけ点数は上がる
	int P = 0;
	for(int i=0;i<N;i++) if(s[i] == 'p') P++;
	cout << N / 2 - P << endl;
}