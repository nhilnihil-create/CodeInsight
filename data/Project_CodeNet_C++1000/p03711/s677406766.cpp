#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int a,b,x[7]={1,3,5,7,8,10,12},y[4]={4,6,9,11},i,c=0,c2=0,d=0,d2=0,e=0,e2=0,flg=0;
	scanf("%d%d",&a,&b);
	for(i=0;i<7;i++){
		if(a==x[i]) c=1;
		if(b==x[i]) c2=1;
	}
	if(c==1&&c2==1) flg=1;
	for(i=0;i<4;i++){
		if(a==y[i]) d=1;
		if(b==y[i]) d2=1;
	}
	if(d==1&&d2==1) flg=1;
	if(a==2) e=1;
	if(b==2) e2=1;
	if(e==1&&e2==1) flg=1;
	if(flg==1) printf("Yes\n");
	else printf("No\n");
	return 0;
}
