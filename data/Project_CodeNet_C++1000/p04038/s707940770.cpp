#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2005;
const int ha=1000000007;
int jc[maxn*maxn],ni[maxn*maxn];
int n,k,f[maxn][maxn];
inline int add(int x,int y)
{
	x+=y;
	return x>=ha?x-ha:x;
}
inline int ksm(int x,int y)
{
	int an=1;
	for(;y;y>>=1,x=x*(ll)x%ha) 
	if(y&1) 
	an=an*(ll)x%ha;
	return an;
}
inline void init()
{
	jc[0]=1;
	for(int i=1;i<=4004000;i++) jc[i]=jc[i-1]*(ll)i%ha;
	ni[4004000]=ksm(jc[4004000],ha-2);
	for(int i=4004000;i;i--) ni[i-1]=ni[i]*(ll)i%ha;
}
inline int getC(int x,int y)
{
	return jc[x]*(ll)ni[y]%ha*(ll)ni[x-y]%ha;
}
inline void dp()
{
	f[0][0]=1;
	for(int i=0;i<=n;i++)
	    for(int j=i;j>=0;j--) 
		if(f[i][j])
		{
	    	f[i+1][j+1]=add(f[i+1][j+1],f[i][j]*(ll)(n-i)%ha*(ll)getC(k*(i+1)-j-2,k-2)%ha);
	    	if(j) 
			f[i][j-1]=add(f[i][j-1],f[i][j]);
		}
}
int main(){
	init();
	cin>>n>>k;
	if(k==1) 
	cout<<"1";
	else{
		dp();
		cout<<f[n][0];
	}
	return 0;
}