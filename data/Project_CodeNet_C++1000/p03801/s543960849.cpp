#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+2;
int ar[N],ans[N];
pair<int,int> lis[N];
set<int> idx;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,l,cnt=0,now;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>ar[i];
		lis[i]={ar[i],i};
	}
	sort(lis+1,lis+1+n);
	now=lis[n].first;
	i=j=n;
	while(j&&lis[i].first==lis[j].first){
		cnt++;
		idx.insert(lis[j].second);
		j--;
	}
	set<int>::iterator ite;
	i=j;
	while(i){
		ite=idx.begin();
		ans[*ite]+=(now-lis[i].first)*cnt;
		while(j&&lis[i].first==lis[j].first){
			idx.insert(lis[j].second);
			cnt++;
			j--;
		}
		now=lis[i].first;
		i=j;
	}
	ite=idx.begin();
	ans[*ite]+=(now-lis[i].first)*cnt;
	for(i=1;i<=n;i++){
		cout<<ans[i]<<'\n';
	}
}