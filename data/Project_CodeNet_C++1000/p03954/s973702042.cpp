#include<bits/stdc++.h>
#include<sys/mman.h>
#define read() Read<int>()
#define lowbit(i) i&(-i)
using namespace std;
typedef long long ll;
const int N=1e6+5;
namespace pb_ds{   
    namespace io{
        const int MaxBuff=1<<15;
        const int Output=1<<23;
        char B[MaxBuff],*S=B,*T=B;
		#define getc() ((S==T)&&(T=(S=B)+fread(B,1,MaxBuff,stdin),S==T)?0:*S++)
        char Out[Output],*iter=Out;
        inline void flush(){
            fwrite(Out,1,iter-Out,stdout);
            iter=Out;
        }
    }
    template<class Type> inline Type Read(){
        using namespace io;
        register char ch;
        register Type ans=0; 
        register bool neg=0;
        while(ch=getc(),(ch<'0' || ch>'9') && ch!='-');
        ch=='-'?neg=1:ans=ch-'0';
        while(ch=getc(),'0'<= ch && ch<='9') ans=ans*10+ch-'0';
        return neg?-ans:ans;
    }
    template<class Type> inline void Print(register Type x,register char ch='\n'){
        using namespace io;
        if(!x) *iter++='0';
        else{
            if(x<0) *iter++='-',x=-x;
            static int s[100]; 
            register int t=0;
            while(x) s[++t]=x%10,x/=10;
            while(t) *iter++='0'+s[t--];
        }
        *iter++=ch;
    }
}
using namespace pb_ds;
int a[N],p[N];	
int n,l,r,ans;
inline bool chk(int x){
	for (int i=1;i<(n<<1);++i) p[i]=a[i]>x;
	for (int i=0;i<n-1;++i){
		if ((!p[n-i] && !p[n-i-1]) || (!p[n+i] && !p[n+i+1])) return 0;
		if ((p[n-i] && p[n-i-1]) || (p[n+i] && p[n+i+1])) return 1;
	}
	return p[1];
}
int main(){
	//freopen("pyramid.in","r",stdin);
	//freopen("pyramid.out","w",stdout);
	n=read();
	for (int i=1;i<(n<<1);++i) a[i]=read();
	l=1,r=(n<<1)-1;
	while (l<=r){
		int mid=(l+r)>>1;
		if (chk(mid)) l=mid+1;
		else r=mid-1,ans=mid;	
	}
	printf("%d\n",ans);
	return 0;
}