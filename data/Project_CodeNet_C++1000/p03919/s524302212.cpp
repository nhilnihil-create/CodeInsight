#include<stdio.h>
#include<string.h>

int main(void){
	
	char str[26][(int)'Z'][6];
	int H,W;
	int i,j;

	scanf("%d %d",&H,&W);

	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			scanf("%s",str[i][j]);
		}
	}
	

	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			if(strcmp("snuke",str[i][j])==0){break;}
		}
			if(strcmp("snuke",str[i][j])==0){break;}
	}

	printf("%c%d\n",(char)(j+(int)'A'),i+1);
	return 0;

}