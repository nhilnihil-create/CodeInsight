#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef unsigned int ui;
int main(){
	int n,a,b;
	vector<int> G[100000];
	cin >> n;
	int i,j;
	for (i = 0; i < n - 1; i++) {
		cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> q1,q2;
	int count1 = 0; int count2 = 0; int used[100000] = {};
	q1.push_back(0); q2.push_back(n-1); used[0] = 1; used[n - 1] = 1;
	while (!((q1.empty())&&q2.empty())) {
		int len = q1.size();
		for (i = 0; i < len; i++) {
			int le = G[q1[i]].size();
			for (j = 0; j < le; j++) {
				if (used[G[q1[i]][j]] == 0) {
					used[G[q1[i]][j]] = 1; q1.push_back(G[q1[i]][j]); count1++;
				}
			}
		}
		for (i = 0; i < len; i++) {
			q1.erase(q1.begin());
		}
		len = q2.size();
		for (i = 0; i < len; i++) {
			int le = G[q2[i]].size();
			for (j = 0; j < le; j++) {
				if (used[G[q2[i]][j]] == 0) {
					used[G[q2[i]][j]] = 1; q2.push_back(G[q2[i]][j]); count2++;
				}
			}
		}
		for (i = 0; i < len; i++) {
			q2.erase(q2.begin());
		}
	}
	if (count1 > count2) {
		cout << "Fennec" << endl;
	}
	else cout << "Snuke" << endl;
	return 0;
}