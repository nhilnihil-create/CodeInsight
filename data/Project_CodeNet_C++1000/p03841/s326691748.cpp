#include <bits/stdc++.h>
using namespace std;
const int N=500*500+5;
int a[N];
struct Node{
	int val,id;
}p[505];
bool cmp(Node a,Node b){
	return a.val<b.val;
}
int main (){
	int n;scanf ("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf ("%d",&p[i].val);
		if (a[p[i].val]) {puts("No");return 0;}
		p[i].id=i,a[p[i].val]=p[i].id;
	}
	sort(p+1,p+n+1,cmp);
	int tot=1;bool flag=true;
	for (int i=1;i<=n;i++)
		for (int j=1;j<p[i].id;j++){
			while (a[tot]) {
				if (a[tot]==p[i].id) flag=false;
				tot++;
			}
			a[tot++]=p[i].id;
		}
	if (!flag) {
		puts("No");
		return 0;
	}
	tot=n*n;
	for (int i=n;i>=1;i--)
		for (int j=1;j<=n-p[i].id;j++){
			while (a[tot]) {
				if (a[tot]==p[i].id) flag=false;
				tot--;
			}
			a[tot--]=p[i].id;
		}
	if (!flag) {
		puts("No");
		return 0;
	}
	puts("Yes");
	for (int i=1;i<=n*n;i++) printf ("%d ",a[i]);
	return 0;
}
