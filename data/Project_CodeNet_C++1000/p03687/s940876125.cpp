#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
template<typename T> void chkmin(T &x,T y){x=x<y?x:y;}
template<typename T> void chkmax(T &x,T y){x=x>y?x:y;}
char S[110];bool in[30];int f[30];

int main(){
	scanf("%s",S+1);int n=strlen(S+1);
	rep(i,1,n){
		if(!in[S[i]-'a'+1])chkmax(f[S[i]-'a'+1],i-1);
		in[S[i]-'a'+1]=1;
		int pos=n+1;
		rep(j,i+1,n){
			if(S[j]==S[i]){pos=j;break;}
		}
		chkmax(f[S[i]-'a'+1],pos-i-1);
	}
	
	int ans=INT_MAX;
	rep(i,1,26){
		if(!in[i])continue;
		chkmin(ans,f[i]);
	}
	write(ans);
	return 0;
}
