//#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f_(i,a,b) for (int i=a;i>=b;i--)
#define f(i,a,b) for (int i=a;i<=b;i++)
 
int n,L,q,x[100005],cha[100005][30];
int main() {
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d", &n);
	f(i,1,n) scanf("%d", &x[i]);
	scanf("%d", &L);
	int it=n;
	f_(i,n,1) {
		while (x[it]-x[i]>L) it--;
		cha[i][0]=it;
	}
	for (int j=1;j<=20;j++) f(i,1,n) cha[i][j]=cha[cha[i][j-1]][j-1];
//	f(i,1,n) cout<<cha[i]<<" ";
//	cout<<"\n";
//	f(i,1,n) cout<<cha2[i]<<" ";
//	cout<<"\n";
	scanf("%d", &q);
	while (q--) {
		int a,b;
		scanf("%d %d", &a, &b);
		if (a>b) {
			a=a+b;
			b=a-b;
			a=a-b;
		}
		int dem=0,pos=a;
		for (int i=20;i>=0;i--) {
			if (cha[pos][i]<b) {
				pos=cha[pos][i];
				dem+=(1<<i);
			}
		}
		printf("%d\n", dem+1);
	}
	return 0;
}