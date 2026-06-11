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

ll n,m,k,cnt;
ll bas[maxn],a[maxn],b[maxn],arr[maxn],pre[maxn];

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	memset(bas,0,sizeof(bas));
	m = 0, cnt = 0;
	n = read(), k=read();
	for(int i=1;i<=n;i++)
	{
		a[i] = read(), b[i] = read(); 
		m = max(m,a[i]);
		bas[a[i]] += b[i];
	}
	
	for(int i=1;i<=m;i++){
		if(bas[i]!=0) arr[++cnt] = i;
	}
	
	for(int i=1;i<=cnt;i++){
		pre[i] = bas[arr[i]];
		pre[i] += pre[i-1];
	}
	
	sort(arr+1,arr+cnt+1);

	for(int i=1;i<=cnt;i++){
		if(pre[i]>=k){
			printf("%d\n",arr[i]);
			break;
		}
	}

//	for(int i=1;i<=cnt;i++){
//		printf("%d ",pre[i]);
//	}printf("\n");
//	for(int i=1;i<=cnt;i++){
//		printf("%d ",bas[arr[i]]);
//	}printf("\n");

	return 0;
}