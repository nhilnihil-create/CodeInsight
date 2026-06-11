#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
#include<cassert>
using namespace std;
typedef long long int LL;
typedef pair<LL,LL> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

int main(){
	LL n,m,t;
	int i,j,k;
	LL a,b,c,d;
	vector<P> vp;
	vector<LL> v[2];
	cin>>n>>m>>t;
	m*=2,t*=2;
	vector<LL> v1(n),v2(n),vs(n);
	for(i=0;i<n;i++){
		cin>>a>>b;
		b--;
		a*=2;
		vp.push_back(make_pair(a,b));
		v[b].push_back(a);
	}
	int cnt=t/m*2;
	int pos=0;
	t%=m;
	if(t*2>=m){
		cnt++;
		t-=m/2;
		pos=m/2;
	}
	for(i=0;i<n;i++){
		a=i;
		if(vp[i].second==0){
			a+=(LL)v[1].size()*cnt;
			a%=n;
		}else{
			a-=(LL)v[0].size()*cnt;
			if(a<0)a+=((-a)/n+1)*n;
			a%=n;
		}
		v1[i]=a;
	}
	//array_show(v1);
	for(i=0;i<n;i++){
		if(vp[i].second==0){
			a=vp[i].first+t*2;
			a%=m;
			auto itr=lower_bound(v[1].begin(),v[1].end(),a);
			b=distance(v[1].begin(),itr);
			itr=lower_bound(v[1].begin(),v[1].end(),vp[i].first);
			c=distance(v[1].begin(),itr);
			if(a<vp[i].first)b+=v[1].size();
			d=i+b-c;
		}else{
			a=vp[i].first-t*2;
			if(a<0)a+=((-a)/m+1)*m;
			a%=m;
			auto itr=upper_bound(v[0].begin(),v[0].end(),a);
			b=distance(v[0].begin(),itr);
			itr=lower_bound(v[0].begin(),v[0].end(),vp[i].first);
			c=distance(v[0].begin(),itr);
			if(a>vp[i].first)c+=v[0].size();
			d=i+b-c;
			if(d<0)d+=n;
		}
		d%=n;
		v2[i]=v1[d];
		
		if(vp[i].second==0){
			a=pos+vp[i].first+t;
		}else{
			a=pos+vp[i].first-t;
			if(a<0)a+=m;
		}
		a%=m;
		vs[v1[d]]=a;
	}
	//array_show(v2);
	for(i=0;i<n;i++){
		cout<<vs[i]/2<<endl;
	}
}