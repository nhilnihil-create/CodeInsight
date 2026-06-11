#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
template <typename T>inline T read()
{
    register T sum=0;
    register char cc=getchar();
    int sym=1;
    while(cc!='-'&&(cc>'9'||cc<'0'))cc=getchar();
    if(cc=='-')sym=-1,cc=getchar();
    sum=sum*10+cc-'0';
    cc=getchar();
    while(cc>='0'&&cc<='9')sum=sum*10+cc-'0',cc=getchar();
    return sym*sum;
}
template <typename T>inline T read(T &a)
{
    a=read<T>();
    return a;
}
template <typename T,typename... Others> inline void read(T& a, Others&... b)
{
    a=read(a);
	read(b...);
}
int n,a[maxn];
int main()
{
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n;i++)
		if(a[i+1]<i+1)
		{
			int j=0;
			while(a[i+1+j]==i)
				j+=1;
			if(((a[i]-i)&1)||(j&1))
				puts("First");
			else
				puts("Second");
			return 0;
		}
    return 0;
}
