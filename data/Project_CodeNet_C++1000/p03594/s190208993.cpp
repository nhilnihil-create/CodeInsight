#include<cstdio>
using namespace std;
int n,m,dis;
char str[5]="BGRY";
int main(){
	scanf("%d%d%d",&n,&m,&dis);
	if (dis&1){
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++) printf("%c",str[i+j&1]);
			printf("\n");
		}
	}
	else{
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++) printf("%c",str[((i+j)/dis&1)+((i-j+10000)/dis&1)*2]);
			printf("\n");
		}
	}
	return 0;
}