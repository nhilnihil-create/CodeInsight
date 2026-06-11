#include<bits/stdc++.h>
#define mo 1000000007
#define pi 3.1415926535898 
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
long long n,m,i,a[100005],book[100005],sum,sum2,max1;
char s[100005];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
   	cin>>n>>a[1];
   	s[1]='+';
   	for(i=2;i<=n;i++)
   		cin>>s[i]>>a[i];
   	for(i=1;i<=n;i++)
   		if(s[i]=='+')
   			book[i]=book[i-1]+a[i];
   		else
   			book[i]=book[i-1]-a[i];
   	max1=book[n];
   	for(i=n;i>=1;i--){
		sum2+=a[i];
		if(s[i]=='-'){
			max1=max(max1,book[i-1]-sum2+sum);
			sum+=sum2;
			sum2=0;
		}
	}
	pus(max1,2);
    return 0;
}