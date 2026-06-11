#include<cstdio>
int h,w,d;
int main()
{
	scanf("%d%d%d",&h,&w,&d);
	for(int i=0;i<h;i++,puts(""))
		for(int j=0;j<w;j++)putchar("RGBY"[((i+j)%(d+d))/d*2+((i-j)%(d+d)<0?((i-j)%(d+d)+d+d)/d:(i-j)%(d+d)/d)]);
	return 0;
}
