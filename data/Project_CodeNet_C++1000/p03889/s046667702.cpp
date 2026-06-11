#include<bits/stdc++.h>
using namespace std;
char s[100005],ss[100005];
signed main(){
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++){
		switch(s[i]){
			case 'b':{ss[len-i-1]='d';break;}
			case 'd':{ss[len-i-1]='b';break;}
			case 'p':{ss[len-i-1]='q';break;}
			case 'q':{ss[len-i-1]='p';break;}
		}
	}
	if(strcmp(s,ss))printf("No");
	else printf("Yes");
	return 0;
}