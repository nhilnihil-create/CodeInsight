#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main(){ _

	int N;
	cin >> N;

	map<int,int> M;

	vector<int> V(N);
	for(auto &x : V) cin >> x, M[x]++;
	
	int cnt = 0;
	for(auto x : M){
		if(x.s == 1) continue;
		cnt += !(x.s & 1);
	}

	cnt &= 1;
	
	cout << M.size() - cnt << endl;

	return 0;
}
