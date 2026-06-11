#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 200010;

int n,m;
int cnt[maxn];

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	int u,v;
	n = read() ,m = read();
	for(int i=1;i<=m;i++){
		u = read(), v = read();
		++cnt[u],++cnt[v];
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",cnt[i]);
	}
	
	return 0;
}