#include"stdio.h"
using namespace std;
int i,ans;
char a[20]={0,'C','O','D','E','F','E','S','T','I','V','A','L','2','0','1','6'},c;
int main(){
	for(i=1;i<=16;i++){
		c=getchar();
		if(c!=a[i]) ans++;
	}
	printf("%d",ans);
	return 0;
}