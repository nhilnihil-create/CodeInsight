#include <cstring>
#include <cstdio>
using namespace std;
char ch[15];
int len;
long long ans;
void dfs(long long sum,long long cnt,int p){
	if(p==len){
		ans+=sum+cnt;
		return;
	}
	if(cnt!=0)dfs(sum+cnt,ch[p]-'0',p+1);
	dfs(sum,cnt*10+ch[p]-'0',p+1);
}
int main(){
	scanf("%s",ch);
	len=strlen(ch);
	dfs(0,0,0);
	printf("%lld\n",ans);
	return 0;
}