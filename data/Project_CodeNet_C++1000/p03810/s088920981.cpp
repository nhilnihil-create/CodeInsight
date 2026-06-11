#include<cstdio>
#include<cstring>
#include<algorithm>
const int N=1e5+10;
int a[N],ma=0,n;
int read(){
	int ans=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-48;c=getchar();}
	return ans*f;
}
/*-----------------------------------------------------*/
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
bool dfs(int p){
	int mc=0,flag=1;
	for(int i=1;i<=n;i++)if(a[i]%2){a[i]--;break;}
	int gc=a[1];
	for(int i=2;i<=n;i++)gc=gcd(gc,a[i]);
	for(int i=1;i<=n;i++){a[i]/=gc;if(!(a[i]%2))mc++;if(a[i]==1)flag=0;}
 	if(mc%2)return !p;
	if(!flag||n-mc!=1)return p;
	return dfs(p^1);
}
int main(){
	n=read();int mc=0;bool flag=1;
	for(int i=1;i<=n;i++){
		a[i]=read();if(a[i]%2==0)mc++;
		else {
			ma++;if(a[i]==1)flag=0;
		}
	} 
	if(mc%2)printf("First");
	else {
		if(ma!=1||!flag)printf("Second");
		else if(dfs(1))printf("First");
		else printf("Second");
	}
	return 0;
}