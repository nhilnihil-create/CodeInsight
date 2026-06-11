
#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<queue>
#include<list>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<cstdio>
#include <iomanip>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i<=b;i++)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

using namespace std;
typedef long long ll;

ll H, W;
int N;
map<ll, int> cnt;
map<int, ll> ans;
//-----------------------------------------------------------------
int main() {
	cin >> H >> W >> N;


	//x,y座標を受け取って、その周りを+1していく。
	//+1されたことのある座標は、mapにぶちこんで記録しておく。
	//pairを使わなくてもxの最大値より大きい値をyにかけておけば、一つの値に圧縮できる。
	//範囲外判定をfor文の判定でやるか、中で別に書くかは微妙。
	rep(i, 0, N) {
		int a, b; cin >> a >> b;

		rep(y, max(1, a - 2), min((ll)a, H - 2) + 1) rep(x, max(1, b - 2), min((ll)b, W - 2) + 1) {
			cnt[(ll)y * 1000000001LL + (ll)x]++;
		}
	}

	//9個の中に黒マスがp.second個ある。
	for (auto p : cnt) {
		ans[p.second]++;
	}

	//ほうじょげんりを使って一つも入ってない正方形を数える。
	ll sm = 0;
	rep(i, 1, 10) sm += ans[i];
	ans[0] = (H - 2) * (W - 2) - sm;

	//出力
	rep(i, 0, 10) cout << ans[i] << endl;
}