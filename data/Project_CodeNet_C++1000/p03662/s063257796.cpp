#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<cmath>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
	std::fill((T*)array, (T*)(array + N), val);
}
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
typedef long long ll;
typedef long double ld;
typedef unsigned long long int ull;
const ll INF = 1LL << 60;
const int inf = 1 << 25;
ll n, m, k, y,x, q, w = 1, sum = 0, ans = 0; string s;
const int MOD = 1000000007;
vector<vector<int>> Gragh;
int main(void) {
	cin >> n; Gragh.resize(n);
	rep(i, n-1) {
		cin >> x >> y;
		Gragh[x - 1].push_back(y - 1);
		Gragh[y - 1].push_back(x - 1);
	}
	vector<int> a(n, -1), b(n, -1);
	queue<int> q,qq; a[0] = 0; b[n - 1] = 0;
	q.push(0); qq.push(0);
	while (!q.empty()) {
		w = q.front(); q.pop();
		x = qq.front(); qq.pop();
		for (int i : Gragh[w]) {
			if (a[i] != -1) continue;
			a[i] = x + 1;
			q.push(i);
			qq.push(x + 1);
		}
	}q.push(n - 1); qq.push(0);
	while (!q.empty()) {
		w = q.front(); q.pop();
		x = qq.front(); qq.pop();
		for (int i : Gragh[w]) {
			if (b[i] != -1)continue;
			b[i] = x + 1; q.push(i);
			qq.push(x + 1);
		}
	}
	rep(i, n) {
		if (a[i] > b[i]) sum++;
		else ans++;
	}if (sum < ans) cout << "Fennec" << endl;
	else cout << "Snuke" << endl;
}