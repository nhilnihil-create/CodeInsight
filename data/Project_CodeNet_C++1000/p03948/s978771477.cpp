#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) unique(v.begin(), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
#define all(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, T;
	cin >> N >> T;
	int a[N];
	rep(i, 0, N) cin >> a[i];

	int min_v[N];
	int min_tmp = a[0];
	min_v[0] = min_tmp;
	rep(i, 1, N) {
		if(min_tmp > a[i]) {
			min_tmp = a[i];
		}
		min_v[i] = min_tmp;
	}

	vector<int> v;
	v.push_back(0);
	rep(i, 1, N) v.push_back(a[i] - min_v[i]);
	vsort(v);
	;
	cout << v.end() - lower_bound(v.begin(), v.end(), v[v.size() - 1]) << endl;



}
