#include<cstdio>
#include<algorithm>
bool cmp(int x,int y){
	return x>y;
}
int n,now,a[100100];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+n+1,cmp);
	for(now=1;a[now]>=now;now++);
	now--;
	if((a[now]-now)%2==0){
		int j;
		for(j=0;a[now+j]>=now;j++);
		if(j&1){
			puts("Second");
			return 0;
		}
	}
	puts("First");
}