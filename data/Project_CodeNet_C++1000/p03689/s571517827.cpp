#include<cstdio>
using namespace std;
int H,W,h,w;
void structure(int id){
	switch(id){
		case 1:{
			const unsigned int HLJ=(19260817)*(25252)*(0x98e);
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
		case 2:{
			
		}break;
		case 3:{
					
		}break;
	}
}
int main(){
	scanf("%d%d%d%d",&H,&W,&h,&w);
	if(H%h||W%w)puts("Yes"),structure(1);
	else puts("No");
	return 0;
}