#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v(3);
	for(auto &i : v) cin >> i;

	sort(v.begin(), v.end());

	bool ans = (v[0] + v[1] == v[2]);

	cout << (!ans ? "No" : "Yes") << endl;

	return 0;
}
