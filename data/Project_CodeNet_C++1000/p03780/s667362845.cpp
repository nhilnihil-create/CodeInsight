#include<bits/stdc++.h>
#define fo(i,a,b) for((i)=(a);i<=(b);i++)
#define rfo(i,a,b) for((i)=(a);i>=(b);i--)
#define inrange(x,y,z) (((x)>=(y))&&((x)<=(z)))
#define ALL(vec) ((vec).begin(),(vec).end())
#define SOR(vec) sort(ALL(vec))
#define UNI(vec) (vec).erase(unique(ALL(vec)),(vec).end())
using namespace std;
int n,k,a[5020];
bitset<5010> dp;
bool Nec(int num){
	dp.reset();
	dp[0]=1;
	for(int i=1;i<=n;i++){
		if(a[i]<k&&i!=num)
			dp|=(dp<<a[i]);
	}
	for(int i=k-a[num];i<k;i++){
		if(dp[i])
			return true;
	}
	return false;
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
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int pos=n+1;
	for(int i=1;i<=n;i++)
		if(a[i]>=k){
			pos=i;
			break;
		}
	a[n+1]=2e9;
	int le=1,ri=pos,mi;
	while(le<ri){
		mi=(le+ri)>>1;
		if(Nec(mi))
			ri=mi;
		else
			le=mi+1;
	}
	cout<<le-1<<endl;
	return 0;
}
