#include<bits/stdc++.h>
#define MAXN 200005
#define INF 16843009
#define LL long long
using namespace std;

LL N,M,K;
LL r = 3;

map<LL,int> cnt;
map<LL,int>::iterator p;

LL ans[MAXN];

void work(LL x, LL y){	
	for(int i=max(x,r);i<=min(x+r-1,N);i++){
		for(int j=max(y,r);j<=min(y+r-1,M);j++){
			++cnt[M*i + j];
		}
	}
	
}

int main(){
	
	cin>>N>>M>>K;
	
	int x,y;
	for(int i=1;i<=K;i++){
		cin>>x>>y;
		work(x,y);
	}
	
	for(p=cnt.begin();p!=cnt.end();p++){
		ans[p->second]++;
		ans[0]--;
	}
	
	ans[0] += (N-r+1) * (M-r+1);
	
	for(int i=0;i<=r*r;i++){
		cout<<ans[i]<<endl;
	}
	
	return 0;
}