#include<cstdio>
#include<cstring>
const int N=2e5+7;
char s[N];
int t,l=1,n,nxt[N][26],qwq[26],qaq[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)if((t|=1<<(s[i]-97))==67108863)++l,t=0;
	for(int i=0;i<26;++i)qwq[i]=n+1;
	t=0;
	for(int i=n;~i;--i){
		memcpy(nxt[i],qwq,sizeof qwq);
		qwq[s[i]-97]=i;
		qaq[i]=qaq[i+1];
		if((t|=1<<(s[i]-97))==67108863)t=0,++qaq[i];
	}
	int nw=0;
	for(int i=1;i<l;++i){
		for(int c=0;c<26;++c){
			int to=nxt[nw][c];
			if(to<=n&&qaq[to+1]<l-i){
				putchar(c+97);
				nw=to;
				break;
			}
		}
	}
	t=0;
	for(int i=nw+1;i<=n;++i)t|=1<<(s[i]-97);
	for(int i=0;i<26;++i)if(t>>i&1^1)return putchar(i+97),0;
	return 0;
}