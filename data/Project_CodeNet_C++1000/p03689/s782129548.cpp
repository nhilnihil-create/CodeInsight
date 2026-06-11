#include <bits/stdc++.h>
using namespace std;
const int N=505;
int H,W,h,w;
int main(){
	cin >> H >> W >> h >> w;
	if (H%h==0&&W%w==0)
		return puts("No"),0;
	puts("Yes");
	int v1=N,v2=N*(w*h-1)+1;
	for (int i=1;i<=H;i++,puts(""))
		for (int j=1;j<=W;j++)
			if (i%h==0&&j%w==0)
				printf("%d ",-v2);
			else
				printf("%d ",v1);
	return 0;
}