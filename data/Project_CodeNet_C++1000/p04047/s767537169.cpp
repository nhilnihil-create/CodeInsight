#include <bits/stdc++.h>
using namespace std;
//mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count());
//int rnd(int x) { return mrand()%x;}
typedef long long ll;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int main(){ 
	vector<int> v;
	int n;
	scanf("%d",&n);
	for(int i=0;i<2*n;i++){
		int tmp;
		scanf("%d",&tmp);
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	ll ans=0;
	for(int i=0;i<(int)v.size();i+=2){
		ans+=min(v[i],v[i+1]);
	}
	printf("%lld\n",ans);
	return 0;
}
