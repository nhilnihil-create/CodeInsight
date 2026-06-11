#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pa;
const int maxn=305;

inline ll rd(){
    ll x=0;char c=getchar();int neg=1;
    while(c<'0'||c>'9'){if(c=='-') neg=-1;c=getchar();}
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*neg;
}

int N,M,a[maxn][maxn],cnt[maxn],flag[maxn];
bool del[maxn];

int main(){
    //freopen("","r",stdin);
	N=rd(),M=rd();
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) a[i][j]=rd();
	for(int i=1;i<=N;i++) cnt[a[i][1]]++,flag[i]=1;
	int ans=1e9;
	for(int i=1;i<=M;i++){
		int ma=0;
		for(int j=1;j<=M;j++) if(cnt[j]>cnt[ma]) ma=j;
		ans=min(ans,cnt[ma]);
		CLR(cnt,0);
		del[ma]=1;
		for(int j=1;j<=N;j++){
			for(;del[a[j][flag[j]]];flag[j]++);
			cnt[a[j][flag[j]]]++;
		}
	}
	printf("%d\n",ans);
    return 0;
}