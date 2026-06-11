//2017-8-22
//miaomiao
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define For(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define Forr(i, a, b) for(int i = (a); i >= (int)(b); --i)

#define N (100000+5)

int r[N], a[N], b[N], ans[N];
int odd[N], even[N], n1, n2;

int main(){
	int n, m, sum = 0;
	
	scanf("%d%d", &n, &m);
	For(i, 1, m){
		scanf("%d", &r[i]);
		sum += r[i];
	}

	if(m == 1){
		printf("%d\n", r[1]);
		if(n == 1) printf("1\n1\n");
		else printf("2\n%d %d\n", 1, r[1]-1);
		return 0;
	}

	if(m == 2 && r[1] == 1 && r[2] == 1){
		printf("1 1\n");
		printf("1\n2\n"); return 0;
	}

	if(m == 2){
		sort(r+1, r+m+1);
		For(i, 1, m) printf("%d ", r[i]); puts("");
		if(r[1] == 1) printf("1\n%d\n", r[1]+r[2]);
		else printf("2\n%d %d\n", r[1]+1, r[2]-1);
		return 0;
	}

	For(i, 1, m) if(r[i]%2) odd[++n1] = r[i]; else even[++n2] = r[i];	
	
	int an = 0;
	if(n1 == 1){
		printf("%d ", odd[1]);
		For(i, 1, n2) printf("%d ", even[i]); puts("");

		if(odd[1] > 1) ans[++an] = odd[1]-1;
		if(n2) ans[++an] = 2; else ans[++an] = 1;
		For(i, 1, n2-1) ans[++an] = even[i];
		if(even[n2] > 1) ans[++an] = even[n2]-1;
	
	}else if(n1 == 2){
		printf("%d ", odd[1]);
		For(i, 1, n2) printf("%d ", even[i]); puts("");
		printf("%d ", odd[2]);

		if(odd[1] > 1) ans[++an] = odd[1]-1;
		ans[++an] = 2;
		For(i, 1, n2) ans[++an] = even[i];
		if(odd[2] > 1) ans[++an] = odd[2]-1;
	}else if(!n1){
		For(i, 1, n2) printf("%d ", even[i]);
		ans[++an] = 1;
		For(i, 1, n2-1) ans[++an] = even[i];
		if(even[n2] > 1) ans[++an] = even[n2]-1;
	}else{
		puts("Impossible"); return 0;
	}

	printf("%d\n", an);
	For(i, 1, an) printf("%d ", ans[i]); puts("");

	return 0;
}