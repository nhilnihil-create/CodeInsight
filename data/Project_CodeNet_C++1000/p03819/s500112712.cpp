#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int,ll> P;
typedef pair<P,P> P2;
const ll INF=100000000000000001;
int l[300001]={};
int r[300001]={};
int x[100001]={};
int n,m;
int addx(int k){
	int s=l[k];
	while(s<=m){
		x[s]++;
		s+=s&-s;
	}
	s=r[k]+1;
	while(s<=m){
		x[s]--;
		s+=s&-s;
	}
	return 0;
}
int sumx(int s){
	int r=0;
	while(s>0){
		r+=x[s];
		s-=s&-s;
	}
	return r;
}

int main() {
	cin>>n>>m;

	vector<int> v[100001];
	for(int i=1;i<n+1;++i){
		cin>>l[i]>>r[i];
		v[r[i]-l[i]+1].push_back(i);
	}
	int ln=n;
	for(int i=1;i<m+1;++i){
		ln-=v[i-1].size();
		int t=ln;
		for(auto it:v[i-1])addx(it);
		for(int j=1;(i*j)<=m;++j)t+=sumx(i*j);
		cout<<t<<endl;
	}
	return 0;
}
