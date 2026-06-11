#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=505;
struct data{
	int x,id,now;
}a[N],b[N];
bool cmp(data a,data b){
	return a.x<b.x;
}
int n,now,x[N*N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].x);
		if(a[i].x<i){
			puts("No");
			return 0;
		}
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		while(a[i].now<a[i].id-1){
			now++;
			if(x[now]){
				continue;
			}
			x[now]=a[i].id;
			a[i].now++;
		}
		if(now>=a[i].x){
			puts("No");
			return 0;
		}
		x[a[i].x]=a[i].id;
		a[i].now++;
	}
	now=n*n+1;
	for(int i=n;i>=1;i--){
		while(a[i].now<n){
			now--;
			if(x[now]){
				continue;
			}
			x[now]=a[i].id;
			a[i].now++;
		}
		if(now<=a[i].x){
			puts("No");
			return 0;
		}
		x[a[i].x]=a[i].id;
		a[i].now++;
	}
	puts("Yes");
	for(int i=1;i<=n*n;i++){
		printf("%d ",x[i]);
	}
	puts("");
	return 0;
}