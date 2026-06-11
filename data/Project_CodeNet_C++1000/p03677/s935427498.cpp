#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 100005;

int n, m, a[MAXN];
lint dx1[MAXN], dx2[MAXN];
lint ret[MAXN];

void range_add(int s, int e, int x){
	if(s > e){
		range_add(s, m-1, x);
		range_add(0, e, x + m-s);
		return;
	}
	dx1[s] += x - s;
	dx1[e+1] -= x - s;
	dx2[s] += 1;
	dx2[e+1] -= 1;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		a[i]--;
	}
	lint D = 0;
	for(int i=2; i<=n; i++){
		D += (a[i] - a[i-1] + m) % m;
		a[i-1] = (a[i-1] + 1) % m;
		range_add(a[i-1], a[i], 0);
	}
	for(int i=1; i<m; i++){
		dx1[i] += dx1[i-1];
		dx2[i] += dx2[i-1];
	}
	for(int i=0; i<m; i++) ret[i] = dx1[i] + dx2[i] * i;
	cout << D - *max_element(ret, ret + m + 1) << endl;
}
