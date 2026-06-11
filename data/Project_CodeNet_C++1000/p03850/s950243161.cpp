#include <bits/stdc++.h>

using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int maxn = 1e5 + 50;
const int mod = 1e9 + 7;

int op[maxn] , a[maxn] , n ,nxt[maxn];
long long prefix[maxn],dp[maxn],neg[maxn];
char s[maxn];

int main(int argc , char * argv[]){
	n=read();
	int pre = 1;
	long long ans = 0;
	op[0] = 1;
	for(int i = 1 ; i <= n ; ++ i){
		a[i] = read();
		if( i != n ){
			scanf("%s",s);
			if(s[0]=='-')
				op[i]=-1;
			else
				op[i]=1;
		}
		if(op[i-1]==-1)
			ans-=a[i];
		else
			ans+=a[i];
	}
	for(int i = 1 ; i <= n ; ++ i){
		prefix[i] = prefix[i - 1] + a[i] * op[i - 1];
		neg[i] = neg[i - 1] - a[i];
	}
	memset(nxt,-1,sizeof(nxt));
	for(int i = n ; i >= 1 ; -- i){
		nxt[i] = nxt[i + 1];
		if(op[i]==-1)
			nxt[i]=i+1;
	}
	dp[n]=a[n]*op[n-1];
	for(int i = n - 1 ; i >= 1 ; -- i){
		dp[i]=dp[i+1]+a[i]*op[i-1];
		if(op[i-1]==-1&&nxt[i]!=-1){
			dp[i]=max(dp[i],-(neg[n]-neg[nxt[i]-1])-(prefix[nxt[i]-1]-prefix[i]+a[i]));
		}
	}
	cout<<dp[1]<<endl;
	return 0;
}