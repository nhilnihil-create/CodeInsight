#include <bits/stdc++.h>
#define mx 100035
int a[mx],n,l,t,x,cnt;

int main(){
    scanf("%d%d%d",&n,&l,&t);
    for (int i=1; i<=n; i++){
        scanf("%d%d",&a[i],&x);
        if(x==1)
        	a[i]+=t;
        else
        	a[i]-=t;
        cnt += a[i]/l;
        if(a[i]%l<0) cnt--;//就是这里细节的处理
        a[i]=((a[i]%l)+l)%l;
    }
    std::sort(a+1,a+n+1);
    cnt=((cnt%n)+n)%n;
	for(int i=cnt+1; i<=n; i++)
		printf("%d\n",a[i]);
    for(int i=1; i<=cnt; i++)
		printf("%d\n",a[i]);
    return 0;
}