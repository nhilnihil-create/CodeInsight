#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define Maxn 100010
#define INF 10010
inline int read()
{
    char c=getchar();re ll f=1,s=0;
    while(!isdigit(c)){if(c=='-')f=-1,c=getchar();}
    while(isdigit(c)){s=s*10+c-48;c=getchar();}
    return f*s;
}
ll f[1000001],ans,n,a,b;
int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++) cin>>f[i];
    for(int i=2;i<=n;i++) ans+=min(a*(f[i]-f[i-1]),b);
    cout<<ans<<endl;
    return 0;
}     