#include <cstdio>
#define rep(i,j,k) for (i=j;i<=k;i++)
using namespace std;
const int N=505;
int H,W,h,w,i,j,bsc;
int main()
{
//	freopen("matrix.in","r",stdin);
//	freopen("matrix.out","w",stdout);
	scanf("%d%d%d%d",&H,&W,&h,&w);
	if (H%h==0 && W%w==0) printf("No\n");
	else {
		bsc=2000;
		printf("Yes\n");
		rep(i,1,H)
		{
			rep(j,1,W)
				if (i%h==0 && j%w==0) printf("%d ",-bsc*(h*w-1)-1);
				else printf("%d ",bsc);
			printf("\n");
		}
	}
	return 0;
}