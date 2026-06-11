#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
#define eprintf(...) fprintf(stderr,__VA_ARGS__)

const int N=int(1e5)+5;
const int mo=int(1e9)+7;

int n;
int x[N];
bool flag[N];
int nex[N];
int fac[N];

int main(){
	scanf("%d",&n);
	int left=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		left+=x[i]-x[i-1]-1;
		if(left){
			flag[i]=true;
			left--;
		}
	}
	nex[n+1]=n+1;
	nex[n+2]=n+2;
	for(int i=n;i>=1;i--)
		nex[i]=(flag[i]?nex[i+1]:i);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*ll(i)%mo;
	int ans=1;
	int st=nex[1];
	int i;
	for(i=0;st<=n;i++){
		ans=ans*ll(st-i)%mo;
		st=nex[st+1];
		st=nex[st+1];
	}
	ans=ans*(ll)fac[n-i]%mo;
	printf("%d\n",ans);
}
