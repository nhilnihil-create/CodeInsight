#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;

int n, a[MAXN];

int main(){
	scanf("%d",&n);
	a[0] = 2e9;
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	auto fun = [&](int v){
		int s = 0, e = n + 1;
		while(s != e){
			int m = (s+e)/2;
			if(a[m] > v) s = m+1;
			else e = m;
		}
		return s;
	};
	int mxp = 0;
	while(a[mxp + 2] >= mxp + 2) mxp++;
	int updiag = a[mxp + 1] - mxp;
	int ridiag = fun(mxp) - mxp - 1;
	bool win = 0;
	if(updiag % 2 == 1 && ridiag % 2 == 1){
		win = 0;
	}
	else{
		win = 1;
	}
	puts(win ? "First" : "Second");
}
