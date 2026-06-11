#include<bits/stdc++.h>
using namespace std;
int n;const int N=1e6+10;const int mod=1e9+7;
template<class T>inline void Inc(T&x,int y){x+=y;if(x>=mod) x-=mod;return;}
int f[N];
typedef long long ll;
int main()
{
	cin>>n;f[n]=n,f[n-1]=(ll)n*n%mod;int s=0;
	for(int i=n-2;i>0;--i) Inc(s,f[i+3]),f[i]=((ll)(n-1)*(n-1)%mod+f[i+1]+s+i+1)%mod;
	cout<<f[1]<<endl;
}
