#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, m, k, cur, a[N * N], b[N][N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n >> m >> k;

	for(int i = 1; i <= k; ++i)
		cin >> a[i];

	for(int i = 1; i <= n; ++i){
		if(i & 1){
			for(int j = 1; j <= m; ++j){
				if(a[cur] == 0)
					cur++;
				b[i][j] = cur;
				a[cur]--;
			}	
		}else{
		    for(int j = m; j >= 1; --j){
				if(a[cur] == 0)
					cur++;
				b[i][j] = cur;
				a[cur]--;
			}
		}
	}

	for(int i = 1; i <= n; ++i, cout << endl)
	for(int j = 1; j <= m; ++j)
		cout << b[i][j] << " ";

	return 0;
}