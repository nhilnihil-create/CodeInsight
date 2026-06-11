#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010;
char str1[N],ans[N];
int n;
bool check(){
	for(int i=3;i<=n;i++){
		if(ans[i-1]=='W'){
			if(str1[i-1]=='o'){
				if(ans[i-2]=='W')ans[i]='S';
				else ans[i]='W';
			}else{
				if(ans[i-2]=='W')ans[i]='W';
				else ans[i]='S';
			}
		}else{
			if(str1[i-1]=='o'){
				if(ans[i-2]=='W')ans[i]='W';
				else ans[i]='S';
			}else{
				if(ans[i-2]=='W')ans[i]='S';
				else ans[i]='W';
			}
		}
	}
	if(ans[1]=='W'){
		if(str1[1]=='x'&&ans[2]!=ans[n])return false;
		if(str1[1]=='o'&&ans[2]==ans[n])return false;
	}else{
		if(str1[1]=='o'&&ans[2]!=ans[n])return false;
		if(str1[1]=='x'&&ans[2]==ans[n])return false;
	}
	if(ans[n]=='W'){
		if(str1[n]=='x'&&ans[1]!=ans[n-1])return false;
		if(str1[n]=='o'&&ans[1]==ans[n-1])return false;
	}else{
		if(str1[n]=='o'&&ans[1]!=ans[n-1])return false;
		if(str1[n]=='x'&&ans[1]==ans[n-1])return false;
	}
	return true;
}
void print(){
	for(int i=1;i<=n;i++)printf("%c",ans[i]);
}
int main(){
	scanf("%d",&n);scanf("%s",str1+1);
	ans[1]='S';
	ans[2]='S';if(check()){print();return 0;}
	ans[2]='W';if(check()){print();return 0;}
	ans[1]='W';
	ans[2]='S';if(check()){print();return 0;}
	ans[2]='W';if(check()){print();return 0;}
	printf("-1");
	return 0;
}