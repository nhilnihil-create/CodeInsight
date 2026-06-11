#include <stdio.h>
#include <stdlib.h>
int main(){
	int W,H,N;
	int a[100],x[100],y[100];
	scanf("%d %d %d",&W,&H,&N);
	int i;
	for(i=0;i<N;i++){
		scanf("%d %d %d",&x[i],&y[i],&a[i]);
	}
	int x1=0,x2=W,y1=0,y2=H;
	for(i=0;i<N;i++){
		switch(a[i]){
		case 1:
			if(x1<x[i])
				x1=x[i];
			break;
		case 2:
			if(x2>x[i])
				x2=x[i];
			break;
		case 3:
			if(y1<y[i])
				y1=y[i];
			break;
		case 4:
			if(y2>y[i])
				y2=y[i];
			break;
		default:break;
		}
	}
	int w,h;
	w = x2>=x1 ? x2-x1 :0;
	h = y2>=y1 ? y2-y1 : 0; 
	printf("%d\n",w*h);
	return 0;
}
