#include<bits/stdc++.h>
using namespace std;
const int N=100007;
char pre[N],fch[N];
int cnt,n;
char change(char ch){
	if(ch=='b')return 'd';
	if(ch=='d')return 'b';
	if(ch=='p')return 'q';
	if(ch=='q')return 'p';
}
int main(){
	pre[1]=getchar();
	cnt=1;
	char ch;
	while(cin>>ch){
		pre[++cnt]=ch;		
	}
	n=cnt++;
	//for(int i=1;i<=cnt;i++)cout<<pre[i];
	for(int i=n;i>=1;i--){
		fch[i]=change(pre[--cnt]);
	}
	cnt=n;
	for(int i=1;i<=n;i++){
		if(fch[i]!=pre[cnt]){
			puts("No");
			return 0;
		}
		cnt--;
	}
	puts("Yes");
	return 0;
}