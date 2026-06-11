#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 100100; 

int n,cnt,ans;
int a[maxn],col[maxn];

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	memset(col,0,sizeof(col));
	cnt=0,ans=0;
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read(); 
		if(a[i]<3200) col[a[i]/400]++;
		else col[8]++;
	}
	
//	for(int i=0;i<=8;i++) printf("%d ",col[i]); printf("\n"); 
	
	for(int i=0;i<=7;i++){
		if(col[i]) cnt++;
	}
	
	if(cnt!=0){
		printf("%d %d\n",cnt,cnt+col[8]);
	}else{
		printf("%d %d\n",1,col[8]);
	}

	return 0;
}