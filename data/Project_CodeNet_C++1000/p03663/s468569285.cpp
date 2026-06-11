#include<bits/stdc++.h>
using namespace std;
char s[100],y[10];
bool ask(int l,int r){
	printf("? ");
	for(int i=l;i>=r;--i)printf("%c",s[i]);
	puts(""),fflush(stdout);
	scanf("%s",y);
	return y[0]=='Y';
}
int main(){
	int len=-1;
	for(int i=1;i<=10;++i){
		s[i]='1';
		if(!ask(i,1)){
			len=i-1;
			break;
		}
		s[i]='0';
	}
	if(len==-1){
		for(int i=1;i<=10;++i){
			s[i]='9';
			if(ask(i,1)){
				len=i;
				break;
			}
		}
	}
	for(int i=1;i<=11;++i)
		s[i]='9';
	for(int i=11;i>=1;--i){
		int l=(i==11?1:0),r=9,ans;
		while(l<=r){
			int mid=l+r>>1;
			s[i]=mid+'0';
			if(ask(11,1))ans=mid,r=mid-1;
			else l=mid+1;
		}
		s[i]=ans+'0';
		if(11-i+1==len){
			printf("! ");
			for(int j=11;j>=i;--j)printf("%c",s[j]);
			puts(""),fflush(stdout);
			return 0;
		}
	}
}