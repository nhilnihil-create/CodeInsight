#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, m, A[100050], ss[100050], linear[100050];
void print(){
	int cur = 0, cur2 = 0;
	for(int i = 1; i<=m; i++){
		cur += linear[i];
		cur2 += ss[i];
		printf("%d ", cur*i+cur2);
	}
	printf("\n");
}
int main(){
//	freopen("mx0.txt","r",stdin);
	cin >> n >> m;
	for(ll i = 0; i<n; i++){
		cin >> A[i];
		if(i == 0) continue;
		int s = A[i-1], t = A[i];
		if(s < t){
			linear[s+1]--;
			linear[t+1]++;
			ss[1] += t-s;
			ss[s+1] -= t-s;
			ss[s+1] += t+1;
			ss[t+1] -= t+1;
			ss[t+1] += t-s;
		}else{
			linear[1]--;
			linear[t+1]++;
			linear[s+1]--;
			ss[1] += t+1;
			ss[t+1] -= t+1;
			ss[t+1] += t+m-s;
			ss[s+1] -= t+m-s;
			ss[s+1] += t+m+1;
		}
	}
	ll ans = 1000000000000;
	for(ll i = 1; i<=m; i++){
		ss[i] += ss[i-1];
		linear[i] += linear[i-1];
		ans = min(ans, linear[i]*i+ss[i]);
	}
	cout << ans;
}
