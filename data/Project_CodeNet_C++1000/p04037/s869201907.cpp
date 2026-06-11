#include<bits/stdc++.h>
#define maxn 100005

using namespace std;

int n;
int a[maxn];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a+0,a+n);
	reverse(a+0,a+n);
	int x=0,y=0;
	while (x+1<n && a[x+1]>x+1) 
		x++;
	while (y<n && a[y]>x)
		y++;
	if ((a[x]-x)&1 && (y-x)&1) puts("Second");
		else puts("First");
}