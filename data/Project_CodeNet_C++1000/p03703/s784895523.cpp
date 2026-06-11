#include <bits/stdc++.h>
using namespace std;
struct BiIndTree{
	long long val[200005];
	inline void init(){
		memset(val,0,sizeof(val));
	}
	inline void add(int x,long long v){
		x++;
		while(x<200005){
			val[x]+=v;
			x+=x&-x;
		} 
	}
	inline long long query(int x){
		x++;
		long long res=0;
		while(x>0){
			res+=val[x];
			x-=x&-x;
		}
		return res;
	}
}bit; 
int n;
long long k;
long long sum[200005];
long long ans;
vector<long long> s;
int main(){
	cin>>n>>k;
	int sz=0;
	sum[sz++]=0;
	for(int i=0;i<n;++i){
		cin>>sum[sz];
		sum[sz]-=k;
		sum[sz]+=sum[sz-1];
		sz++;
	}
	for(int i=0;i<sz;++i){
		s.push_back(sum[i]);
	}
	sort(s.begin(),s.end());
	s.erase(unique(s.begin(),s.end()),s.end());
	bit.init();
	for(int i=0;i<sz;++i){
		int pos=lower_bound(s.begin(),s.end(),sum[i])-s.begin();
		ans+=bit.query(pos);
		bit.add(pos,1);
	} 
	cout<<ans<<'\n';
	return 0;
}