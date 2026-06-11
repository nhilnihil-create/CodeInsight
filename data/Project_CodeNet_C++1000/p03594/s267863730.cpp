#include <iostream>
#include <cstdio>
using namespace std;

int H, W, d;

int main(){
	scanf("%d%d%d", &H, &W, &d);
	for(int i=1; i<=H; i++)
		for(int j=1; j<=W; j++){
			int x=(i+j)/d%2, y=(i-j+W)/d%2;
			if(x==1 && y==1)	putchar('R');
			if(x==1 && y==0)	putchar('G');
			if(x==0 && y==1)	putchar('B');
			if(x==0 && y==0)putchar('Y');
			if(j==W)	putchar('\n');
		}
	return 0;
}