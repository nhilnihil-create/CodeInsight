#include<bits/stdc++.h>
using namespace std;

int W,H,w,h;

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	H=read();W=read();h=read();w=read();
	if (H%h==0&&W%w==0) printf("No\n");
	else {
		printf("Yes\n");
		for (int i=1;i<=H;i++)
			for (int j=1;j<=W;j++)
				printf((j!=W)?"%d ":"%d\n",(i%h==0&&j%w==0)?-1000*(w*h-1)-1:1000);
	}
	return 0;
}