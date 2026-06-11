#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

deque<int> build(int64 v){
	if (v == 1) return {};

	if (v & 1){
		auto answer = build(v - 1);
		int val = answer.size() + 1;
		answer.push_front( val );
		return answer;
	}
	else{
		auto answer = build(v / 2);
		int val = answer.size() + 1;
		answer.push_back( val );
		return answer;
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int64 n;
	cin >> n;

	auto perm = build(n + 1);

	cout << 2 * perm.size() << endl;

	for (auto u : perm) cout << u << " ";

	for (int i = 1; i <= (int)perm.size(); ++i)
		cout << i << " ";

	cout << endl;

	return 0;
}