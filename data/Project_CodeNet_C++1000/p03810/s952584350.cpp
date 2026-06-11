#include <iostream>
#include <cstdio>
using namespace std;
int n,a[100001],odd,sum;
int gcd(int x,int y){
	if (!y) return x;
	return gcd(y,x%y);
}
int f(){
	int o=0,e=0,i,g;
	for (i=1;i<=n;++i)
		if (a[i]&1){
			++o;
			odd=i;
		}else ++e;
	if (o==1&&a[odd]!=1){
		--a[odd];
		g=a[1];
		for (i=2;i<=n;++i) g=gcd(g,a[i]);
		for (i=1;i<=n;++i) a[i]/=g;
		return 1-f();
	}else{
		for (i=1;i<=n;++i) sum+=a[i];
		if ((sum+n)&1) return 1;
		else return 0;;
	}
}
void read(int& x){
    x=0;
    int y=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') y=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    x=x*y;
}
int main(){
	int i;
	read(n);
	for (i=1;i<=n;++i) read(a[i]);
	if (f()) printf("First\n");
	else printf("Second\n");
	return 0;
}