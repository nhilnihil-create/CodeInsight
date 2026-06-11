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

	int n;
	 cin >> n;
	 int p[n];
	 rep(i, 0, n) {
		 cin >> p[i];
		 p[i]--;
	 }

	 int cnt = 0;
	 if(p[0] == 0) {
		 swap(p[0], p[1]);
		 cnt++;
	 }

	 rep(i, 1, n - 1) {
		 if(i == p[i]) {
			 swap(p[i], p[i + 1]);
			 cnt++;
		 }
	 }
	 if(p[n - 1] == n - 1) cnt++;

	 cout << cnt << endl;

}
