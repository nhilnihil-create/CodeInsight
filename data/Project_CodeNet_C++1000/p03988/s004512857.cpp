#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define gg return 0
const int N=105;
int a[N],b[N];
int main (){
	int n,L=0;scanf ("%d",&n);
	for (int i=1;i<=n;i++) scanf ("%d",&a[i]),L=max(L,a[i]),b[a[i]]++;
	if (L&1){
		int l=(L+1)/2;
		for (int i=1;i<l;i++) if (b[i]) {puts("Impossible");gg;}
		if (b[l]!=2) {puts("Impossible");gg;}
		for (int i=l+1;i<=L;i++) if (b[i]<2) {puts("Impossible");gg;} 
	}else{
		int l=L/2;
		for (int i=1;i<l;i++) if (b[i]) {puts("Impossible");gg;}
		if (b[l]!=1) {puts("Impossible");gg;}
		for (int i=l+1;i<=L;i++) if (b[i]<2) {puts("Impossible");gg;}
	}
	puts("Possible");
	return 0;
}