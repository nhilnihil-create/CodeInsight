#include<bits/stdc++.h>
#define fo(i,a,b) for((i)=(a);i<=(b);i++)
#define rfo(i,a,b) for((i)=(a);i>=(b);i--)
#define inrange(x,y,z) (((x)>=(y))&&((x)<=(z)))
#define ALL(vec) ((vec).begin(),(vec).end())
#define SOR(vec) sort(ALL(vec))
#define UNI(vec) (vec).erase(unique(ALL(vec)),(vec).end())
#define MOD 1000000007
using namespace std;
int n,m,pri[1024];
long long res;
long long Facto(int x){
	m=n;
	int cnt=0;
	while(m)
		cnt+=(m/x),m/=x;
	return cnt;
}
int main(){
	#ifdef FILIN
		#ifndef DavidDesktop
			freopen(FILIN,"r",stdin);
			freopen(FILOUT,"w",stdout);
		#endif
	#endif
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	res=1LL;
	pri[2]=1;
	for(int i=3;i<=n;i+=2) pri[i]=1;
	for(int i=3;i<=n;i+=2)
		if(pri[i])
			for(int j=i*3;j<=n;j+=i*2)
				pri[j]=0;
	for(int i=1;i<=n;i++){
		if(pri[i]){
			res=(res*(Facto(i)+1LL))%MOD; 
		}
	}
	cout<<res<<endl;
	return 0;
}

