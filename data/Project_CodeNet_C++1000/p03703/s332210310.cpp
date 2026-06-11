#include <bits/stdc++.h>
using namespace std;

long long N,K,ans=0;
vector<long long> a;
vector<long long> sum(1,0);
vector<long long> b;
long long bit[222222];

void add(long long a,long long w){
	for(long long x=a;x<=N+1;x+=x&-x)bit[x]+=w;
}

long long bit_sum(long long a) {
	long long ret=0;
	for(long long x=a;x>0;x-=x&-x)ret+=bit[x];
	return ret;
}

int main(){
	cin >> N >> K;
	for(int i=0;i<N;i++){
		long long tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for(int i=0;i<N;i++){
		sum.push_back(sum[i]+a[i]);
	}
	for(int i=0;i<=N;i++){
		b.push_back(sum[i]-i*K);
	}
	vector<pair<long long,long long>> bb(N+1);
	for(int i=0;i<=N;i++){
		bb[i].first=b[i];
		bb[i].second=i+1;
	}
	sort(bb.begin(),bb.end());
	
	for(auto BB:bb){
		ans+=bit_sum(BB.second);
		add(BB.second,1LL);
	}
	
	cout << ans << endl;
	return 0;
}