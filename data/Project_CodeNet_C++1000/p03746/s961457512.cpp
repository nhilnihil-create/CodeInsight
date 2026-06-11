#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;
ll MOD = 1e9+7;
//LLONG_MIN



int main(void){
	ll n,m,visited[100010]={};
	vector<ll> v[100010];
	deque<ll> Q;
	cin>>n>>m;
	rep(i,m){
		ll a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	reg(i,1,n){//次数が１以上の点を選ぶ
		if(v[i].size()>=1){
			//最初の点から適当な方向に詰まるまで探索．
			ll c=i;
			Q.push_front(c);
			visited[c]=1;
			while(true){
				bool update=false;
				rep(j,v[c].size()){
					ll d=v[c][j];
					if(visited[d]==0){
						c=d;
						Q.push_front(c);
						visited[c]=1;
						update=true;
						break;
					}
				}
				if(!update)break;//通れる点がなくなったら出る
			}
			//最初の点から別の方向に詰まるまで探索．
			c=i;
			while(true){
				bool update=false;
				rep(j,v[c].size()){
					ll d=v[c][j];
					if(visited[d]==0){
						c=d;
						Q.push_back(c);
						visited[c]=1;
						update=true;
						break;
					}
				}
				if(!update)break;//通れる点がなくなったら出る
			}
			break;
		}
	}
	cout<<Q.size()<<endl;
	while(!Q.empty()){
		printf("%lld",Q.front());
		Q.pop_front();
		if(Q.size()>0)printf(" ");
	}
	printf("\n");
	return 0;
}