#include<bits/stdc++.h>
using namespace std;

char s[5];
int h,w,d;

int main(){
    int i,j,x,y;
	s[0]='R',s[1]='Y',s[2]='G',s[3]='B';
    scanf("%d%d%d",&h,&w,&d);
    for(i=0;i<h;++i){
    	for(j=0;j<w;++j){
    		x=((w+i+j)/d)&1;
    		y=((w+i-j)/d)&1;
    		printf("%c",s[x*2+y]);
    	}
    	puts("");
    }
}