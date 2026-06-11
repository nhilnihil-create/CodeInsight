#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = 2*1e18;
const int inf = 1e9+7;

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,M;
	cin >> N >> M;
	int ans = N;
	vector<vector<int>> A(N,vector<int>(M));
	vector<bool> h(M,1);
	rep(i,N)rep(j,M){
		cin >> A[i][j];
		A[i][j]--;
	}
	int cnt = M;
	while(cnt){
		vector<int> p(M);
		rep(i,N){
			rep(j,M){
				int now = A[i][j];
				if(h[now]){
					p[now]++;
					break;
				}
			}
		}
		int t = 0;
		int next = 0;
		rep(j,M){
			if(t<p[j]){
				t = p[j];
				next = j;
			}
		}
		ans = min(ans,t);
		h[next] = 0;
		cnt--;
	}
	cout << ans << endl;
}
