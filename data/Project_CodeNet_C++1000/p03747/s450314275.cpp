#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<set>
using namespace std;
typedef pair<int, int> pii;
typedef double lf;
typedef long long ll;
const int inf=0x3f3f3f3f, mod=1000000007;
int pos[100100];

inline int read()
{
    int x=0,f=1; char ch=getchar();
    for (; ch<'0' || ch>'9'; ch=getchar()) if (ch=='-') f=-1;
    for (; ch>='0' && ch<='9'; ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}

int main()
{
    int n=read(), l=read(), t=read(), start=0;
    for (int i=1; i<=n; i++)
    {
        pos[i]=read(); int w=read();
        if (w==1) pos[i]+=t; else pos[i]-=t;
        start+=pos[i]/l;
        if (pos[i]%l<0) start--;
        pos[i]=(pos[i]%l+l)%l;
    }
    sort(pos+1, pos+n+1); start=(start%n+n)%n;
    for (int i=start+1; i<=n; i++) printf("%d\n",pos[i]);
    for (int i=1; i<=start; i++) printf("%d\n",pos[i]);
    return 0;
}
