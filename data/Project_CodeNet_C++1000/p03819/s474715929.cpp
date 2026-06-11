#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 998244353
#define ll long long
using namespace std;
int N;
ll data[530000],datb[530000];
void init(int n_){
	N = 1;
	while(N<n_)N*=2;
}
void add(int a,int b, int x,int k,int l,int r){
	if(a <= l && r<=b){
		data[k] += x;
	}
	else if( l<b && a<r ){
		datb[k] += (min(b,r)-max(a,l)) * x;
		add( a,b,x,k*2+1,l,(l+r)/2);
		add( a,b,x,k*2+2,(l+r)/2,r);
	}
}
ll sum(int a,int b,int k,int l,int r){
	if(b<=l || r<=a){
		return 0;
	}
	else if(a<= l && r<=b){
		return data[k]*(r-l)+datb[k];
	}
	else{
		ll res = (min(b,r) -max(a,l)) * data[k];
		res += sum(a,b,k*2+1,l,(l+r)/2);
		res += sum(a,b,k*2+2,(l+r)/2,r);
		return res;
	}
}
signed main(){
	int n,m;
	cin>>n>>m;
	init(114514);
	int kakujitu = n;
	priority_queue< pair< int, pair<int,int> > > que;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		que.push( mp( x-y-1, mp(x,y) ) );
	}
	for(int i=1;i<=m;i++){
		int ans = 0;
		while( !que.empty() && -1 * que.top().first < i){
			//cout<<-1*que.top().first<<" "<<i<<endl;
			pair<int,int> P = que.top().second; que.pop();
			kakujitu--;
			int cl = P.first;
			int cr = P.second;
			//cout<<cl<<" "<<cr<<endl;
			add( cl, cr+1, 1, 0, 0, N);
		}
		for(int j=1;j*i<=m;j++){
			ans += sum( j*i, j*i+1, 0, 0, N);
			//cout<<"pos "<<j*i<<" "<<sum( j*i, j*i+1, 0, 0, N)<<endl;
		}
		ans += kakujitu;
		cout<<ans<<endl;
	}
	return 0;
}