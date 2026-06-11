#include<bits/stdc++.h>
#define EM 100000000
using namespace std;
using LL = long long;
using P = pair<LL, LL>;
LL LINF = 1e18;
int INF = 1e9;
LL mod = 1e9+7;
using vint = vector<int>;
using vLL = vector<LL>;
using vvint = vector<vector<int>>;
using vvLL = vector<vector<LL>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	int N, K;
	cin >> N >> K;
	vector<int> a(N), b(N);
	vector<vector<int>> bit(N, vector<int>(31, 0));
	for(int i = 0;i < N;i++)	cin >> a[i] >> b[i];
	for(int i = 0;i < N;i++){
		for(int j = 30;j >= 0;j--){
			if(((a[i]>>j)&1) == 0 && (((a[i]>>(j+1)) | (K>>(j+1))) == (K>>(j+1))))	bit[i][j] = 1;
		}
	}
	LL ans = 0;
	for(int i = 30;i >= 0;i--){
		if(K&(1<<i)){
			LL res = 0;
			for(int j = 0;j < N;j++){res += bit[j][i]*b[j];}
			ans = max(ans, res);
		}
	}
	LL res = 0;
	for(int i = 0;i < N;i++){if((a[i] | K) == K)	res += b[i];}
	ans = max(ans, res);
	cout << ans << endl;
}