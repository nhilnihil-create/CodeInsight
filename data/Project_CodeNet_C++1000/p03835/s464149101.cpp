#include<cstdio>
using namespace std;
int k,s,c=0,z;
int main(){
	scanf("%d %d",&k,&s);
	if (s==k*3){
		c=1;
	}else{
		for (int x=0;x<k+1;x++){
			for (int y=0;y<k+1;y++){
				if ((s-x-y>=0)&&(s-x-y<k+1)){
					c+=1;
				}
			}
		}
	}
	printf("%d",c);
return 0;}