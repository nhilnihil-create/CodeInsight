#include<cstdio>
using namespace std;
int ans;
char stdstr[]="CODEFESTIVAL2016",st[16];
int main(){
	gets(st);
	for(int i=0;i<=15;i++) if(stdstr[i]!=st[i]) ans++;
	printf("%d\n",ans);
	return 0;
}