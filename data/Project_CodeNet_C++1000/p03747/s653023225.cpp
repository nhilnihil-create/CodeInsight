#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read() {
    char ch = getchar(); ll x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}
int weiyi;
int a[100050];
int main(){
	int n=read(),L=read(),T=read();
	for (int i=1;i<=n;i++)
	{
		int x=read(),w=read();
		w=3-w*2;
		x+=w*T;
		if (x>=L)	weiyi+=(x/L);
		if (x<0)	weiyi-=((-x)+(L-1))/L;
		a[i]=(x%L+L)%L;
	}
	sort(a+1,a+1+n);
	weiyi=(weiyi%n+n)%n;
	for (int i=1;i<=n;i++)
	 printf("%d\n",a[(i+weiyi-1)%n+1]);
}