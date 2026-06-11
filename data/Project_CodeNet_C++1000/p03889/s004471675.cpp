#include<cstdio>
#include<cstring>
char c[100005],s[100005];
int main(){
	bool flag=0;
	scanf("%s",c+1);
	strcpy(s,c+1);
	int n=strlen(c+1);
	for(int i=1;i*2<=n;++i){
		if(c[i]!=c[strlen(c)-i+1]){flag=1;break;}
	}
	if(flag==0){printf("Yes\n");return 0;}
	flag=0;
	for(int i=1;i<=n;++i){
		if(c[i]=='b')c[i]='d';
		else if(c[i]=='d')c[i]='b';
		else if(c[i]=='p')c[i]='q';
		else c[i]='p';
	}
	if(strcmp(c+1,s)==0){printf("Yes\n");return 0;}
	for(int i=1;i*2<=n;++i){
		char w=c[i];
		c[i]=c[n-i+1];
		c[n-i+1]=w;
	}
	if(strcmp(c+1,s)==0){printf("Yes\n");}
	else printf("No\n");
    return 0;
}
