#include <cstdio>
int main(){
	int H,W,h,w;
	scanf("%d%d%d%d",&H,&W,&h,&w);
	if (H%h==0 && W%w==0){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	if (H%h){
		for (int i=0;i<H;i++,printf("\n"))
			for (int j=0;j<W;j++)
			if (i%h==0) printf("%d ",(h-1)*1000-1);
				else printf("-1000 ");
	}
	else
		for (int i=0;i<H;i++,printf("\n"))
			for (int j=0;j<W;j++)
			if (j%w==0) printf("%d ",(w-1)*1000-1);
				else printf("-1000 ");
}