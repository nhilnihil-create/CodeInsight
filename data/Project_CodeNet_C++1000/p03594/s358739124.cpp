#include<bits/stdc++.h>
using namespace std;
int N=501;
int h,w,d;
char s[4]={'R','Y','G','B'};
int main(){
	scanf("%d%d%d",&h,&w,&d);
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			int x=(i+j+w)/d;
			int y=(i-j+w)/d;
			putchar(s[(x&1)*2+(y&1)]);
		}
		cout<<endl;
	}
}