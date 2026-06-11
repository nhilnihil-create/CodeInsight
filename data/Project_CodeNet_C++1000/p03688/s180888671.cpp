#include<cstdio>
const int N=100002;
int n,a[N],i,x=1<<30,y=0,l,r,s;
int max(int x,int y){
	return x>y?x:y;
}
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		x=min(x,a[i]);
		y=max(y,a[i]);
	}
	if(y-x>1){
		printf("No");
		return 0;
	}
	if(x==y){
		l=1;r=n/2;
		if(l<=x&&x<=r||x==n-1)
			printf("Yes");
		else
			printf("No");
		return 0;
	}
	for(i=1;i<=n;i++)
		if(a[i]==x)
			s++;
	if(s==n-1){
		printf("No");
		return 0;
	}
	l=s+1;
	r=s+(n-s)/2;
	if(l<=y&&y<=r)
		printf("Yes");
	else
		printf("No");
}
	