#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
int l[MAXN],a[MAXN],b[MAXN],ans,n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],b[a[i]]++,l[a[i]%m]++;
	for(int i=1;i<m;i++){
		int j=m-i;
		int minn=min(l[i],l[j]);
		if(i==j){
			ans+=l[i]/2;
			l[i]%=2;
			continue;
		}
		ans+=minn;
		l[i]-=minn;
		l[j]-=minn;
	}
	ans+=l[0]/2;
	l[0]%=2;
	for(int i=1;i<=100000;i++){
		while(b[a[i]]>=2){
			if(l[a[i]%m]>=2){
			 	ans++;l[a[i]%m]-=2;
			 }
			else break;
			b[a[i]]-=2;
		}
	}
	cout<<ans<<endl;
}