#include <bits/stdc++.h>
int n,b[505*505];
struct note{
	int x,i;
}a[505];
bool cmp(note x,note y){
	return x.x<y.x;
}
void ex(){
	puts("No");
	exit(0);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].x),a[i].i=i;
	int N=n*n;
	std::sort(a+1,a+n+1,cmp); 
	for (int i=1;i<=n;i++){
		int now=1;
		for (int j=1;j<a[i].x && now<a[i].i;j++)
			if (!b[j]) b[j]=a[i].i,now++;
		b[a[i].x]=a[i].i;
		if (now<a[i].i) ex();
	}
	for (int i=n;i>=1;i--){
		int now=n;
		for (int j=N;j>=a[i].x && now>a[i].i;j--)
			if (!b[j]) b[j]=a[i].i,now--;
		if (now>a[i].i) ex();
	}
	puts("Yes"); 
	for (int i=1;i<=N;i++) printf("%d ",b[i]);
} 