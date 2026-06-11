#include<bits/stdc++.h>
#define mo 1000000007
#define pi 3.1415926535898
#define eps 1e-9 
using namespace std;
long long read(){
    long long xx=0,flagg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
int n,i,j,a[100005],ans;
bool cmp(int u,int v){
	return u>v;
}
int main(){
	n=read();
	for(i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
		if(i+1>a[i+1]){
			for(j=i+1;a[j]==i;j++)
				ans^=1;
			if((a[i]-i)&1)
				ans=1;
			if(ans==1)
				printf("First\n");
			else
				printf("Second\n");
			return 0;
		}
    return 0;
}