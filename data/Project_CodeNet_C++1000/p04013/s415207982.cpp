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
const int MAX = 55;

vector<vector<ll>> DP(MAX,vector<ll>(MAX*MAX,0));

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N,A;
	cin >> N >> A;

	DP[0][0] = 1;

	vector<int> V(N);
	for(auto &x : V) cin >> x;

	for(int i = 0; i < N; i++){
		for(int j = i; j >= 0; j--){
			for(int k = 0; k < MAX*MAX; k++){
				if(k + V[i] < MAX*MAX)
					DP[j+1][k+V[i]] += DP[j][k];
			}
		}
	}

	ll ans = 0;
	for(int i = 1; i <= N; i++) ans += DP[i][i*A];

	cout << ans << endl;	

	return 0;
}
