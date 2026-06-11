#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
using namespace std;

//union find木(グループわけができる)
int par[600050];
int unifind(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
	}
	return 0;
}
//木の根を求める
int unifind_root(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = unifind_root(par[x]);
	}
}
//同じグループか判定
bool unifind_same(int x, int y) {
	return unifind_root(x) == unifind_root(y);
}
//グループ併合
int unifind_unite(int x, int y) {
	x = unifind_root(x);
	y = unifind_root(y);
	if (x == y) {
		return 0;
	}
	par[x] = y;
}
struct STRUCT{
	long long int x, y, id;
};
bool cmp(STRUCT A, STRUCT B) {
	if (A.x != B.x) { return A.x < B.x; }
	else { return A.y < B.y; }
}
int main() {
	complex<long double>cmpmp;
	const long long int mod = 1000000007;
	map<long long int, long long int>mp;
	//cout << fixed << setprecision(10);
	STRUCT tmp[200005];
	long long int N, K, L, p[200050], q[200050], res[600005] = {},p2[200050],q2[200050],now=1;
	cin >> N>>K>>L;
	unifind(600005);
	for (int i = 0; i < K; i++) {
		cin >> p[i]>>q[i];
		unifind_unite(p[i], q[i]);
	}
	for (int i = 0; i < L; i++) {
		cin >> p2[i] >> q2[i];
		unifind_unite(p2[i] + 200000, q2[i] + 200000);
	}
	for (int i = 1; i <= N; i++) {
		tmp[i].x = unifind_root(i);
		tmp[i].y = unifind_root(i+200000);
		tmp[i].id = i;
	}
	sort(tmp + 1, tmp + N + 1,cmp);
	for (int i = 1; i < N; i++) {
		if (tmp[i].x == tmp[i + 1].x && tmp[i].y == tmp[i + 1].y) {
			now++;
		}
		else {
			for (int j = i - now+1; j <= i; j++) {
				res[tmp[j].id] += now;
			}
			now = 1;
		}
	}
		
	for (int j = N - now+1; j <= N; j++) {
		res[tmp[j].id] += now;
	}
	
	for (int i = 1; i <= N; i++) {
		std::cout << res[i] << " ";
	}
}
