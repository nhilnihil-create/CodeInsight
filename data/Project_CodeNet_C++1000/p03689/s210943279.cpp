#include<cstdio>
using namespace std;
int H,W,h,w;
void structure(int id){
	switch(id){
		case 0:{
			const unsigned int HLJ=19260817*981;
			int HLL=HLJ%998244853;
			for(int i=0;i<H;i++){
    				for(int j=0;j<W;j++){
    					printf("%d%c",
    					((i%h)||(j%w))?
    					(
    					(((i+1)%h)||((j+1)%w))
    					?(0)
    					:(-HLL-1)
    					):HLL,(j+1)!=W?' ':'\n');
				}
    			}
		}break;
		case 1:{
			int EVA=25252;
			if(H%h){
				for(int i=1;i<=H;i++){
					if(i%h)for(int j=1;j<=W;j++)
						printf("%d%c",EVA,j!=W?' ':'\n');
					else for(int j=1;j<=W;j++)
						printf("%d%c",-EVA*(h-1)-1,j!=W?' ':'\n');
				}
			}else{	
				for(int i=1;i<=H;i++){
					for(int j=1;j<=W;j++)
					if(j%w)
						printf("%d%c",EVA,j!=W?' ':'\n');
					else
						printf("%d%c",-EVA*(w-1)-1,j!=W?' ':'\n');
				}
			}
		}break;
	}
}
#include<algorithm>
#include<ctime>
int main(){
	srand(time(0));
	scanf("%d%d%d%d",&H,&W,&h,&w);
	if(H%h||W%w)puts("Yes"),structure(1);
	else puts("No");
	return 0;
}