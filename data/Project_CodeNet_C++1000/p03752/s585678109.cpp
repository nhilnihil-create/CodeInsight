#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long n,k;
	cin>>n>>k;
	vector<long long> tower(n);
	vector<long long> tallest(n,-1);
	for(long long i=0;i<n;i++){
		cin>>tower.at(i);
		tallest.at(i)=max(tallest.at(max((long long)0,i-1)),tower.at(i));
	}

	long long ans=inf*1000;

	for(long long tmp=0;tmp<(1<<n);tmp++){
		bitset<15> bits=tmp;
		long long cnt=0;
		for(long long i=0;i<n;i++){
			if(bits.test(i)) cnt++;
		}
		if(cnt!=k) continue;

		long long pre=0;
		vector<long long> high=tallest;
		for(long long i=0;i<n;i++){
			if(!bits.test(i)) continue;

			if(i==0 || high.at(i-1)<tower.at(i)){
				pre+=0;
			}else{
				pre+=high.at(i)-tower.at(i)+1;

				long long now=high.at(i)+1;
				for(long long j=i;j<n;j++){
					high.at(j)=max(high.at(j),now);
				}
			}
		}

		ans=min(ans,pre);
	}

	cout<<ans<<endl;

	return 0;
}
