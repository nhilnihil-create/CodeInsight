//#pragma GCC optimize(3)
#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<set> 
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define ll long long
#define db double
#define inf 200009
#define INF (int)1e8 
#define mod (int)(1e9+7)
#define pi acos(-1)
#define rd(n) {n=0;char ch;int f=0;do{ch=getchar();if(ch=='-'){f=1;}}while(ch<'0'||ch>'9');while('0'<=ch&&ch<='9'){n=(n<<1)+(n<<3)+ch-48;ch=getchar();}if(f)n=-n;}
using namespace std;

int a[inf],p[inf];
int n;

bool check(int k){
	for (int i=1;i<=n*2-1;i++){
		p[i]=(a[i]>=k);
	}
	int posl=0,posr=n*2;
	for (int i=n;i>=2;i--){
		if (p[i]==p[i-1]){
			posl=i;
			break;
		}
	}
	for (int i=n;i<n*2-1;i++){
		if (p[i]==p[i+1]){
			posr=i;
			break;
		}
	}
	if (posl==0 && posr==n*2){
		return p[1];
	}
	else if (n-posl>posr-n){
		return p[posr];
	}
	return p[posl];
}

int main(){
	rd(n)
	for (int i=1;i<=n*2-1;i++){
		rd(a[i])
	}
	int l=2,r=n*2-2,ans;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	printf("%d\n",ans);
	return 0;
}