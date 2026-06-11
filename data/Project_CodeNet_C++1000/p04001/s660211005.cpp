#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1LL << 60)
#define rep(i, n) for(int i=0; i<(n); ++i)

//初級編
//https://qiita.com/drken/items/e77685614f3c6bf86f44

//確率DP
//https://atcoder.jp/contests/dp/tasks/dp_i
//LCS
//https://atcoder.jp/contests/dp/tasks/dp_f
//グラフ
//https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c

int main()
{
	string S; cin >> S;
	auto bitcalc = [&](int bit)
	{
		int from = 0;
		int to = 1;
		vector<ll> num;
		while (bit > 0) {
			if (bit & 1) {
				num.push_back(stoi(S.substr(from, to - from)));
				from = to;
			}
			bit = bit >> 1;
			++to;
		}
		num.push_back(stoll(S.substr(from, S.size() - from)));
		ll sum = 0;
		rep(i, num.size()) sum += num[i];
		return sum;
	};
	ll ans = 0;
	rep(i, 1 << (S.size() - 1)) ans += bitcalc(i);
	cout << ans << endl;
}
