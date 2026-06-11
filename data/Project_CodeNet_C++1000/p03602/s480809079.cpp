#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long int ll;
typedef pair<ll,int> P;
const ll INF = 100000000000;
int main(){
	int n;
	ll a[300][300];
	ll b[300][300];
	ll ans = 0;
	priority_queue<P,vector<P>,greater<P> > pq;
	scanf("%d",&n);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%lld",&a[i][j]);
	for(int i=0;i<n;i++) for(int j=0;j<i;j++) pq.push(make_pair(a[i][j],n*i+j));
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) b[i][j] = INF;
	while(!pq.empty()){
		P now = pq.top(); pq.pop();
		ll cost = now.first;
		int h = now.second / n;
		int w = now.second % n;
		bool flag = false;
		b[h][w] = b[w][h] = a[h][w];
		for(int k=0;k<n;k++){
			if(k==h||k==w) continue;
			if(b[h][k]+b[k][w]<cost){
				printf("-1\n");
				return 0;
			}else if(b[h][k]+b[k][w]==cost){
				flag = true;
			}
		}
		if(!flag) ans += cost;
	}
	printf("%lld\n",ans);
}
