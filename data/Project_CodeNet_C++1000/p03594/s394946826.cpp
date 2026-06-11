#include<cstdio>
int h,w,d;
int main()
{
	scanf("%d%d%d",&h,&w,&d);
	for(int i=0;i<h;i++,puts(""))
		for(int j=0;j<w;j++)putchar("RGBY"[(i+j)/d%2*2+(i>=j?(i-j)/d%2:(j-i+d-1)/d%2)]);
	return 0;
}
