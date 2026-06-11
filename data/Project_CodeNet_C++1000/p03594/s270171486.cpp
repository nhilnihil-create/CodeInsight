#include<cstdio>
int h,w,d;
char s[]="RGBY";
int main(){
	scanf("%d%d%d",&h,&w,&d);
	if(d&1){
		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j)putchar(s[i+j&1]);
			putchar(10);
		}
	}else{
		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j){
				int x=i+j,y=i-j+10000;
				putchar(s[(x/d&1)+(y/d&1)*2]);
			}
			putchar(10);
		}
	}
	return 0;
}