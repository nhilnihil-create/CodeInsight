#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char ch[100002];
bool p,d;
int a;

int main(){
	scanf("%s",&ch);
	a=strlen(ch);
	for(int i=0;i<=a/2+1;++i)
		if(ch[i]!=ch[a-i-1]){
			p=true;
			break;
		}
	for(int i=0;i<=a/2+1;++i)
				if((ch[i]=='p'&&ch[a-i-1]!='q')||(ch[i]=='q'&&ch[a-i-1]!='p')||(ch[i]=='b'&&ch[a-i-1]!='d')||(ch[i]=='d'&&ch[a-i-1]!='b')){
					d=true;
					break;
				}
	if(p&&d) printf("No");
	else printf("Yes");
	return 0;
}
