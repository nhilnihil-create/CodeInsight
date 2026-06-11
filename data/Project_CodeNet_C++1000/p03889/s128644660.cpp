#include<cstdio>
#include<cstring>
const int maxl=1e5+5;
int len;char a[maxl],b[maxl];
int main(){
	#ifdef local
	freopen("data.in","r",stdin),freopen("data.out","w",stdout);
	#endif
	scanf("%s",a);len=strlen(a);
	for(int i=0;i<len;++i)
	  switch(a[i]){
	  	case 'b':b[i]='d';break;
	  	case 'd':b[i]='b';break;
	  	case 'p':b[i]='q';break;
	  	case 'q':b[i]='p';break;
	  }
	for(int i=0;i<len;++i)
	  if(a[i]^b[len-i-1]) return printf("No\n"),0;
	return printf("Yes\n"),0;
}