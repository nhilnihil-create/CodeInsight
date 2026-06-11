#include<bits/stdc++.h>
#define gc getchar()
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,v) rep(i,0,(int)v.size()-1)
#define lint long long
#define db double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln <<endl
using namespace std;
typedef pair<int,int> pii;
typedef set<int>::iterator sit;
inline int inn()
{
	int x,ch;while((ch=gc)<'0'||ch>'9');
	x=ch^'0';while((ch=gc)>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^'0');return x;
}
const int N=100010;lint ps[N],ss[N];int a[N],sg[N],R[N];
inline lint S(int l,int r) { if(l>r) return 0;return ss[r]-ss[l-1]; }
int main()
{
	int n=inn();a[1]=inn(),ps[1]=a[1],ss[1]=a[1];
	for(int i=1;i<n;i++)
	{
		while((sg[i]=gc)!='+'&&sg[i]!='-');a[i+1]=inn();
		if(sg[i]=='+') ps[i+1]=ps[i]+a[i+1];
		else ps[i+1]=ps[i]-a[i+1];ss[i+1]=ss[i]+a[i+1];
	}
	R[n]=n;lint ans=ps[n];for(int i=n-1;i;i--) if(sg[i]=='+') R[i]=R[i+1];else R[i]=i;
	rep(i,1,n-1) if(sg[i]=='-')
		ans=max(ans,ps[i]-S(i+1,R[i+1])+ss[n]-ss[R[i+1]]);
	return !printf("%lld\n",ans);
}