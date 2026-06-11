#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char buf[1<<15],*fs,*ft;
inline char getc() { return (ft==fs&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),ft==fs))?0:*fs++; }
template<typename T>inline void read(T &x)
{
    x=0;
    T f=1, ch=getchar();
    while (!isdigit(ch) && ch^'-') ch=getchar();
    if (ch=='-') f=-1, ch=getchar();
    while (isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
    x*=f;
}

char Out[1<<24],*fe=Out;
inline void flush() { fwrite(Out,1,fe-Out,stdout); fe=Out; }
template<typename T>inline void write(T x)
{
    if (!x) *fe++=48;
    if (x<0) *fe++='-', x=-x;
    T num=0, ch[20];
    while (x) ch[++num]=x%10+48, x/=10;
    while (num) *fe++=ch[num--];
    *fe++='\n';
}

int a[8];
int main()
{
	for (int i=1; i<=7; ++i) read(a[i]);
	ll ans=a[2];
	if (!a[1] || !a[4] || !a[5]) ans+=a[1]/2*2+a[4]/2*2+a[5]/2*2;
	else
	{
		ans+=(ll)a[1]+a[4]+a[5];
		if (a[1]%2==a[4]%2 && a[4]%2==a[5]%2);
		else --ans;
	}
	write(ans);
	flush();
	return 0;
}