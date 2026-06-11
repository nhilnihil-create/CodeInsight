#include<bits/stdc++.h>
using namespace std;
int n;
long long k,pref[200100],a;
int di;
vector<long long> dis;
template<typename T,int sz>
struct binary_indexed_tree{
	#define lowbit(x)  ((x)&(-x))
	T dat[sz];
	void update(int x,T delta){
		for(;x<sz;x+=lowbit(x)){
			dat[x]+=delta;
		}
	}
	T get(int x){
		T res=0;
		for(;x;x-=lowbit(x)){
			res+=dat[x];
		}
		return res;
	}
};
binary_indexed_tree<int,262144> Bi;
int main(){
	#ifdef FILIN
		#ifndef LOCAL
			freopen(FILIN,"r",stdin);
			freopen(FILOUT,"w",stdout);
		#endif
	#endif
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	pref[0]=0LL;
	for(int i=1;i<=n;i++){
		cin>>a;
		a-=k;
		pref[i]=pref[i-1]+a;
		dis.push_back(pref[i]);
	}
	dis.push_back(0);
	sort(dis.begin(),dis.end());
	dis.erase(unique(dis.begin(),dis.end()),dis.end());
	long long res=0LL;
	di=lower_bound(dis.begin(),dis.end(),0)-dis.begin()+1;
	Bi.update(di,1);
	for(int i=1;i<=n;i++){
		di=lower_bound(dis.begin(),dis.end(),pref[i])-dis.begin()+1;
		res+=(long long)(Bi.get(di));
		Bi.update(di,1);
	}
	cout<<res<<endl;
	return 0;
}
