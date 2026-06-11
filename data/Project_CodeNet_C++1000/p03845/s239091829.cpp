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

	int N;
	cin >> N;

	ll sum = 0;
	vector<int> V(N);

	for(auto &i : V) cin >> i, sum += i;

	int Q;
	cin >> Q;

	while(Q--){
		int p,x;
		cin >> p >> x;
		p--;

		cout << sum + (x - V[p]) << endl;
	}

	return 0;
}
