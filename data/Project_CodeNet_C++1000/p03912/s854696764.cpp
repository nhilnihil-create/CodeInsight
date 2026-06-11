#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())

lli data[100010];
lli odd[100010];
lli even[100010];

signed main(){

	lli n,k;
	cin>>n>>k;

	REP(i,0,n){
		lli tmp;
		cin>>tmp;
		data[tmp]++;
	}

	for(lli i=1;i<100010;i++){
		if(data[i]>0){
			if(data[i]%2){
				odd[i%k]++;
				data[i]--;
			}
			even[i%k]+=data[i];
		}
	}

	lli ans=0;

	//割った余りが0だけ特殊なので処理する
	ans += odd[0]/2;
	ans += even[0]/2;

	//また割った余りが半分の時一致すると厄介なので処理する
	if(k%2==0){
		ans += odd[k/2]/2;
		ans += even[k/2]/2;
	}

	for(lli i=1;i<=k/2;i++){
		if(i == k/2 && k%2==0)continue;
		lli next = k-i;
		if(DEBUG)cout<<"i="<<i<<" next="<<next<<endl;
		if(DEBUG)cout<<"ans="<<ans<<endl;
		lli cnt = min(odd[i],odd[next]);
		if(DEBUG)cout<<"odd[i]="<<odd[i]<<" odd[next]="<<odd[next]<<endl;
		if(DEBUG)cout<<"even[i]="<<even[i]<<" even[next]="<<even[next]<<endl;
		odd[i]-=cnt;
		odd[next]-=cnt;
		ans += cnt;

		if(odd[i]>0){
			cnt=0;
			if(DEBUG)cout<<"odd[i]="<<odd[i]<<" even[next]="<<even[next]<<endl;
			cnt = min(odd[i],even[next]);
			odd[i]-=cnt;
			even[next]-=cnt;
			ans+=cnt;
		}
		if(odd[next]>0){
			cnt=0;
			if(DEBUG)cout<<"odd[next]="<<odd[next]<<" even[i]="<<even[i]<<endl;
			cnt = min(odd[next],even[i]);
			odd[next]-=cnt;
			even[i] -=cnt;
			ans += cnt;
		}

		ans += even[i]/2;
		ans += even[next]/2;
	}

	cout<<ans<<endl;

	return 0;
}