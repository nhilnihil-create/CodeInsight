//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimise ("ofast")
#pragma GCC optimise("unroll-loops")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;
const ll LOG = 25;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x;
	cin >> x;
	int sm = 0;
	int Now = 1;
	while (1){
		sm += Now;
		if (sm >= x) return cout << Now, 0;
		//else if(sm > x) return cout << Now + 1, 0;
		Now++;
	}












	return 0;
}
