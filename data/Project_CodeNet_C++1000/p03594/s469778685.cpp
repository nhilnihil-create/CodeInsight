#include<bits/stdc++.h>
using namespace std;

int main(){
	int h,w,d;
	scanf("%d%d%d",&h,&w,&d);
	for(int i=0;i<h;++i){
		for(int j=0;j<w;++j){
			int x=i+j,y=i-j+w;
			bool f=((x/d)%2==0),g=((y/d)%2==0);
			if(f){
				if(g) printf("R");
				else printf("Y");
			}else{
				if(g) printf("G");
				else printf("B");
			}
		}
		printf("\n");
	}
}