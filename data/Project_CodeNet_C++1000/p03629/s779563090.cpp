#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#define re register
#define maxn 250000
#define mod 1000000007
#define ll long long
using namespace std;
int last,cnt,sum=26;
char s[maxn];
bool vis[maxn];
int L[maxn],R[maxn];
char ans;

int main(){
	scanf("%s",s);
	int len=strlen(s);
	R[0]=len-1;
	for(re int i=len-1;i>=0;i--){
		if(vis[s[i]-'a']==0){
			sum--;
			vis[s[i]-'a']=1;
			if(sum==0){
				L[cnt]=i;
				cnt++;
				R[cnt]=i-1;
				sum=26;
				memset(vis,0,sizeof(vis));
			}
		}
	}
	L[cnt]=0;
	char ans;
	for(re int i=cnt;i>=0;i--){
		memset(vis,0,sizeof(vis));
		for(re int j=last;j<=R[i];j++){
			vis[s[j]-'a']=1;
		}
		for(re int j=0;j<26;j++){
			if(!vis[j]){
				printf("%c",j+'a');
				ans=j+'a';
				break;
			}
		}
		for(re int j=last;j<len;j++){
			if(s[j]==ans){
				last=j+1;
				break;
			}
		}
	}
	return 0;
}