#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
int sub;
ll res;
ll A[100100];
char op[100100];

ll calc(int s) {
	if (s==n) return 0;
	if (s==n-1||op[s+1]=='-') return A[s];
	int p; ll tmp = A[s];
	for (p=s+1;p<n&&op[p]=='+';p++) {
		tmp += A[p];
	}
	return min(A[s]+calc(p),tmp);
}

int main() {
	int i;

	scanf("%d",&n);
	for (i=0;i<n;i++) {
		if (i==0) scanf("%lld",&A[i]);
		else scanf(" %c %lld",&op[i],&A[i]);
	}
	for (i=0;i<n;i++) res += A[i];
	for (i=1;i<n;i++) if (op[i]=='-') break;
	if (i==n) {
		printf("%lld\n",res);
		return 0;
	}
	printf("%lld\n",res-2*calc(i));

    return 0;
}
