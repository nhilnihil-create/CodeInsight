#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const int MOD = 998244353;
const ll INF = 1000000000000000000;

/*
・最終的な文字列は2文字からなる。
・先頭と末尾が同じとき最終的な長さは奇数。
・違うときは偶数。
|S|=9 S[0]!=S[8] 1 1 First
|S|=9 S[0]==S[8] 1 0 Second
|S|=8 S[0]!=S[7] 0 1 Second
|S|=8 S[0]==S[7] 0 0 FIrst
*/
int main()
{
	string S;
	cin >> S;
	int L = S.size();
	int c = (S[0] == S[L - 1]) ? 0 : 1;
	L %= 2;
	if (L ^ c) cout << "Second" << endl;
	else cout << "First" << endl;
}