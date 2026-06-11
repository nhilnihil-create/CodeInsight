#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P2;
const int inf=1000000000;
int pa[200001]={};
int ra[200001]={};
int pa2[200001]={};
int ra2[200001]={};

int find(int xx){
	if(pa[xx]==xx)return xx;
	return pa[xx]=find(pa[xx]);
}
int same(int xx,int yy){
	return 	find(xx)==find(yy);
}
void unite(int xx,int yy){
	xx=find(xx);
	yy=find(yy);
	if(ra[xx]<ra[yy]){
		pa[xx]=yy;
	}else{
		pa[yy]=xx;
		if(ra[xx]==ra[yy])ra[xx]++;
	}
	return;
}
int find2(int xx){
	if(pa2[xx]==xx)return xx;
	return pa2[xx]=find2(pa2[xx]);
}
int same2(int xx,int yy){
	return 	find2(xx)==find2(yy);
}
void unite2(int xx,int yy){
	xx=find2(xx);
	yy=find2(yy);
	if(ra2[xx]<ra2[yy]){
		pa2[xx]=yy;
	}else{
		pa2[yy]=xx;
		if(ra2[xx]==ra2[yy])ra2[xx]++;
	}
	return;
}


int main() {
	int n,k,l;
	vector<P> v;

	cin>>n>>k>>l;
	for(int i=1;i<n+1;++i)pa[i]=i;
	for(int i=1;i<n+1;++i)pa2[i]=i;

	for(int i=0;i<k;++i){
		int p1,q1;
		cin>>p1>>q1;
		if(!same(p1,q1))unite(p1,q1);
	}
	for(int i=0;i<l;++i){
		int r1,s1;
		cin>>r1>>s1;
		if(!same2(r1,s1))unite2(r1,s1);
	}
	for(int i=1;i<n+1;++i){
		P p1=P(find(i),find2(i));
		v.push_back(p1);
//		cout<<p1.first<<" "<<p1.second<<endl;
	}
	sort(v.begin(),v.end());

	P p1=P(find(1),find2(1));
	int t=upper_bound(v.begin(),v.end(),p1)-lower_bound(v.begin(),v.end(),p1);
	cout<<t;
	for(int i=2;i<n+1;++i){
		P p1=P(find(i),find2(i));
		int t=upper_bound(v.begin(),v.end(),p1)-lower_bound(v.begin(),v.end(),p1);
		cout<<" "<<t;
	}
	cout<<endl;
	return 0;
}
