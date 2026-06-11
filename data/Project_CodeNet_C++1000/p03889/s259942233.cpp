#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
char a[maxn],b[maxn];
int main(){
	scanf("%s",b+1);
	int len=strlen(b+1);
	for(int i=1;i<=len;i++){
		a[i]=b[i];
		if(a[i]=='b') a[i]='d';
		else if(a[i]=='d') a[i]='b';
		else if(a[i]=='p') a[i]='q';
		else if(a[i]=='q') a[i]='p';
	}
	int flag=0;
	for(int i=1;i<=len;i++){
		if(b[i]!=a[len-i+1]){
			flag=1;
//			cout<<a[i]<<" "<<a[len-i+1];
			break;
		}
	}
	if(flag==1) cout<<"No";
	else cout<<"Yes";
	return 0;
} 