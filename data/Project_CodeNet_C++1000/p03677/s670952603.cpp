#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N=100005; 

using namespace std;

int n,m,t,a[N]; 
long long ans,cnt,mx; 

struct node{
	int c,lim;
	node(){}
	node(int _c,int _lim){ c=_c; lim=_lim; }
	friend bool operator<(node A,node B){
		return A.lim>B.lim;
	}
}; 

node ys[N<<1]; int num; 
vector<int> list[N]; 

multiset<int> s;
multiset<int>::iterator it;  

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	ans=0; 
	for(int i=1; i<n; ++i){
		if(a[i]==a[i+1]) continue; 
		if(a[i]<a[i+1]) ans+=(a[i+1]-a[i]);
		else ans+=(m-a[i]+a[i+1]); 
	}
	for(int i=1; i<n; ++i){
		if(a[i]==a[i+1]) continue; 
		else{
			if(a[i]<a[i+1]) ys[++num]=node(-a[i]-1,a[i+1]); 
			else{
				ys[++num]=node(-a[i]-1,m); 
				list[a[i]].push_back(-a[i]-1); 
				ys[++num]=node(-1+(m-a[i]),a[i+1]); 
			}
		}
	}
	sort(ys+1,ys+num+1); 
	t=m; 
	cnt=mx=0; 
	for(int i=1; i<=num; ++i){
		for(; t>ys[i].lim && t>0; --t){
			int siz=list[t].size();
			for(int j=0; j<siz; ++j){
				it=s.find(list[t][j]); 
				if(it!=s.end()) cnt-=(*it),s.erase(it);  
			}
		}
		while(1){
			it=s.begin();
			if(it==s.end()) break; 
			//printf("%d\n",(*it));  
			if((*it)<=-ys[i].lim) cnt-=(*it),s.erase(it);  
			else break; 
		}
		cnt+=ys[i].c; 
		s.insert(ys[i].c); 
		mx=max(mx,cnt+(long long)(s.size()*ys[i].lim)); 
	}
	printf("%lld\n",ans-mx); 
	return 0; 
}