/*
ID:wmj20041
TASK:
LANG:C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9+7;
int n,m;
ll a[100005],b[100005],c[1000005];
string s;
bool prime(int n)
{
    if(n==1) return false;
    if(n==2||n==3) return true;
    if(n%6!=1&&n%6!=5) return false;
    for (int i=5;i*i<=n;i+=6)
    if (n%i==0||n%(i+2)==0) return false;
    return true;
}
int check(int x,int y)
{
	if (x>n||x<1||y>=m||y<0) return 0;
	return 1;
}
long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}
inline int read()
{
    int X=0,w=1;
	char c=getchar();
    while (c<'0'||c>'9')
    {
		if (c=='-') w=-1;
		c=getchar();
    }
    while (c>='0'&&c<='9')
	{
	 	X=(X<<3)+(X<<1)+c-'0';
		c=getchar();
	}
    return X*w;
}
int main()
{
    ll sum=0;
    cin>>n>>m>>a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>a[i-1])
        {
            sum+=a[i]-a[i-1];
            b[a[i-1]+1]+=a[i-1]+1;
            b[a[i]+1]-=a[i-1]+1;
            c[a[i-1]+1]++;
            c[a[i]+1]--;
        }
        else
        {
            sum+=m-a[i-1]+a[i];
            b[a[i-1]+1]+=a[i-1]+1;
            c[a[i-1]+1]++;
            b[1]-=m-a[i-1]-1;
            c[1]++;
            b[a[i]+1]+=m-a[i-1]-1;
            c[a[i]+1]--;
        }
    }
    for(int i=1;i<=m;i++)
    b[i]+=b[i-1],c[i]+=c[i-1];
    ll ans=0;
    for(int i=1;i<=m;i++)
    ans=max(ans,ll(i*c[i]-b[i]));
    cout<<sum-ans;
    return 0;
}