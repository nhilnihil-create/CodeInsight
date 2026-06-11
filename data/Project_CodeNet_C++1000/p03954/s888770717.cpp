#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 1000006

using namespace std;

int n;
int a[N], b[N];

bool check(int);

int main(){
	scanf("%d", &n);n = n * 2 - 1;
	int l = 999999999, r = 0, ans;
	for(int i = 1; i <= n; ++i)
		scanf("%d",a + i), l = min(l, a[i]), r = max(r, a[i]);
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;	
	//	cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}

bool check(int x){
	int cnt1 = 0, cnt2 = 0;
	for(int i = 1; i <= n; ++i)
		if(a[i] >= x) b[i] = 1, ++cnt1;
		else b[i] = 0, ++cnt2;
	b[0] = -1;b[n + 1] = -1;
	int pos = n / 2 + 1, tmp1 = 0, tmp2 = 0;
	while(b[pos + tmp1 + 1] != b[pos + tmp1] && pos + tmp1 <= n) ++tmp1;
	while(b[pos - tmp2 - 1] != b[pos - tmp2] && pos - tmp2 >= 1) ++tmp2;
//	cout << x << endl;for(int i = 1; i <= n; ++i) cout << b[i] << ' ';cout << endl;cout << tmp1 << ' ' << tmp2 << endl;
	if(tmp1 == tmp2){
		if(pos - tmp2 == 0)
			return cnt1 > cnt2;	
		else return b[pos - tmp1];
	}
	else{
		if(tmp1 < tmp2) return b[pos + tmp1];
		else return b[pos - tmp2];
	}
}