#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
map<pair<int,int>,int> mp;
int x[N],y[N];
int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};
int ans[N];
signed main(){
	int h,w,n;
	scanf("%lld%lld%lld",&h,&w,&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		mp[make_pair(x[i],y[i])]++;
		for(int j=0;j<8;j++){
			int tx=dx[j]+x[i];
			int ty=dy[j]+y[i];
			if(tx>=1&&ty>=1&&tx<=h&&ty<=w){
				mp[make_pair(tx,ty)]++;
			}
		}
	}
	int sum=0;
	ans[0]=(h-2)*(w-2);
	map<pair<int,int>,int> ::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		int tx=it->first.first;
		int ty=it->first.second;
		int num=it->second;
		if(tx>=2&&ty>=2&&tx<=h-1&&ty<=w-1){
			ans[mp[make_pair(tx,ty)]]++;
			sum++;
		}
	}
	ans[0]-=sum;
	for(int i=0;i<=9;i++) cout<<ans[i]<<'\n';
	return 0;
}