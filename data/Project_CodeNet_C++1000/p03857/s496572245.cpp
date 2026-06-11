#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <cmath>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;
const int MAX_V=2e5;

vector<int> RD[MAX_V+1];
vector<int> TR[MAX_V+1];
int a[MAX_V+1],b[MAX_V+1];

void dfsrd(int v,int c){
	a[v]=c;
	rep(i,RD[v].size()){
		if(a[RD[v][i]]==0)dfsrd(RD[v][i],c);
	}
}
void dfstr(int v,int c){
	b[v]=c;
	rep(i,TR[v].size()){
		if(b[TR[v][i]]==0)dfstr(TR[v][i],c);
	}
}

int main(){
	int N,K,L;
	cin>>N>>K>>L;
	rep(i,K){
		int p,q;
		cin>>p>>q;
		RD[p].push_back(q);
		RD[q].push_back(p);
	}
	rep(i,L){
		int p,q;
		cin>>p>>q;
		TR[p].push_back(q);
		TR[q].push_back(p);
	}
	int crd=1,ctr=1;
	rep1(i,N){
		if(a[i]==0){
			dfsrd(i,crd);
			crd++;
		}
	}
	rep1(i,N){
		if(b[i]==0){
			dfstr(i,ctr);
			ctr++;
		}
	}
	lli x[MAX_V],y[MAX_V];
	rep(i,N)x[i]=y[i]=(lli)(a[i+1]-1)*N+b[i+1]-1;
	sort(y,y+N);
	rep(i,N){
		cout<<upper_bound(y,y+N,x[i])-lower_bound(y,y+N,x[i])<<" ";
	}
}