#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int res=0;
    char c;
    bool zf=0;
    while(((c=getchar())<'0'||c>'9')&&c!= '-');
    if(c=='-')zf=1;
    else res=c-'0';
    while((c=getchar())>='0'&&c<='9')res=(res<<3)+(res<<1)+c-'0';
    if(zf)return -res;
    return res;
}
signed main(){
	int x=read(),y=read();
	if(x==0){
		if(y>0)printf("%d\n",y);
		else printf("%d\n",-y+1);
	}
	else{
		if(y==0){
			if(x>0)printf("%d\n",x+1);
			else printf("%d",-x);
		}
		else{
			if(x>0&&y>0){
				if(x<=y)printf("%d\n",y-x);
				else printf("%d\n",x-y+2);
			}
			else{
				if(x>0&&y<0){
					printf("%d\n",abs(x+y)+1);
				}
				else{
					if(x<0&&y>0){
						printf("%d\n",abs(x+y)+1);
					}
					else{
						if(x<=y)printf("%d\n",y-x);
						else printf("%d\n",x-y+2);
					}
				}
			}
		}
	}
	return 0;
}