#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=1ll<<60;
int n,x; ll f[3];
char Getchar(){
    static char now[1<<20],*S,*T;
    if (T==S){
        T=(S=now)+fread(now,1,1<<20,stdin);
        if (T==S) return EOF;
    }
    return *S++;
}
int read(){
    int x=0,f=1;
    char ch=Getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') f=-1;
        ch=Getchar();
    }
    while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
    return x*f;
}
int main(){
	n=read();
	f[0]=0; f[1]=-INF; f[2]=-INF;
	for (int i=1;i<=n;i++){
		x=read();
		f[0]+=x; f[1]-=x; f[2]+=x;
		if (x<0) f[2]=max(f[1],f[2]),f[1]=max(f[0],f[1]);
		f[0]=max(f[0],f[1]); f[1]=max(f[1],f[2]);
	}
	printf("%lld\n",f[0]);
	return 0;
}
