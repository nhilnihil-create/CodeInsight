#include<bits/stdc++.h>

using namespace std;

int len;
long ans;
char s[10];

void dfs(long sum, long cnt, int k);

int main(void){
    cin >> s;
    len=strlen(s);
    dfs(0,0,0);
    printf("%ld\n",ans);
    return 0;
}

void dfs(long sum, long cnt, int k){
	if(k==len){
		ans+=sum+cnt;
		return;
	}
    // +を挿入した場合
	if(cnt!=0)
        dfs(sum+cnt,s[k]-'0',k+1);
    // +を挿入しない場合
	dfs(sum,cnt*10+s[k]-'0',k+1);
}
