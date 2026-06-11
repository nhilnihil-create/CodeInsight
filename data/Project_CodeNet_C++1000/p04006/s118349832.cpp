#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
long long arr[N],mn[N][N];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
  	int n;
  	long long x;
  	cin >> n >> x;
  	for(int i = 0;i < n;++i)cin >> arr[i];
  	for(int i = 0;i < n;i++){
  	    mn[i][0] = arr[i];
  	    for(int j = 1;j <= n;j++){
  	        mn[i][j] = min(mn[i][j - 1], arr[(i + j) % n]);
  	    }
  	}
  	long long ans = (long long)1e18;
  	for(int i = 0;i <= n;i++){
  	    long long cnt = i * x;
  	    for(int j = 0;j < n;j++){
  	        cnt += mn[j][i];
  	    }
  	    ans = min(ans, cnt);
  	}
  	cout << ans;
  	return 0;
} 