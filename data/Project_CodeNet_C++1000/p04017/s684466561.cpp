#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
const int MX = 100005;
int n, x[MX], nx[MX][20], l, q, a, b, ans, k;
int main(){
	scanf("%d", &n);
	rep(i,n) scanf("%d", x+i);
	scanf("%d%d", &l, &q);
	rep(i,n){
		while(a < n && x[a] - x[i] <= l) a++;
		a--;
		nx[i][0] = a;
	}
	rep(j,19) rep(i,n) nx[i][j+1] = nx[nx[i][j]][j];
	rep(i,q){
		scanf("%d%d", &a, &b);
		a--; b--; ans = 0;
		if(a > b) swap(a,b);
		while(a < b){
			for(k = 0; nx[a][k] < b; k++);
			if(k) k--;
			ans += 1 << k;
			a = nx[a][k];
		}
		printf("%d\n", ans);
	}
}