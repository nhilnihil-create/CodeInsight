#include<iostream>

#include <vector>
#include <list>
#include<stack>
#include<queue>
#include<array>

#include <set>
#include<map>

#include<string>
#include<stdlib.h>

#include<algorithm>
#include <functional>
#include<math.h>

#include<fstream>
#include<iomanip>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

#define FOR(k,m,n) for(ll (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<<str<<endl

constexpr int INF = (1 << 30);
constexpr ll INFL = (1ll << 60);
constexpr ll MOD = 1000000007;// 10^9+7


//変数
ll N, K;
vector<ll> a;
vector<vector<ll>> children;





//サブ関数
//入力
void input()
{
	cin >> N >> K;
	REP(i, N) {
		ll tmp;
		cin >> tmp;
		tmp--;
		a.push_back(tmp);
	}
	children.resize(N);
	REP(i, N)children[a[i]].push_back(i);
}

bool isCapitalSafe()
{
	return (a[0] == 0);
}

void search_deeper(vector<ll>& deep, ll target)
{
	if (deep[target] == -1) {
		search_deeper(deep, a[target]);
		deep[target] = deep[a[target]] + 1;
	}
}

priority_queue<pair<ll, ll>> pq_deeper()
{
	vector<ll> deep(N, -1);
	deep[0] = 0;
	REP(i, N) search_deeper(deep, i);
	
	priority_queue<pair<ll, ll>> pq;
	REP(i, N)pq.push({ deep[i],i });
	return pq;
}

ll upper_node(pair<ll, ll> now, ll dist)
{
	ll p = now.second;
	REP(i, dist)p = a[p];
	return p;
}

void tree_cut(vector<bool>& searched, ll root)
{
	queue<ll> q;
	q.push(root);
	while (!q.empty()) {
		auto node = q.front(); q.pop();
		searched[node] = true;
		for (auto child : children[node]) {
			if (!searched[child]) {
				q.push(child);
			}
		}
	}
}

//計算
void calc()
{
	int res = 0;
	if (!isCapitalSafe())res++;
	a[0] = 0;

	auto pq = pq_deeper();
	vector<bool> searched(N, false);
	searched[0] = true;
	while (!pq.empty()) {
		auto now = pq.top(); pq.pop();
		if (now.first <= K)break;
		if (searched[now.second])continue;
		ll p = upper_node(now, K - 1);
		tree_cut(searched, p);
		res++;
	}
	cout << res << endl;
}


//出力
void output()
{

}


//デバッグ
void debug()
{
	int N;
	cin>>N;
}


//メイン関数
int main()
{
	input();
	calc();
	output();
	debug();
	
	return 0;
}
