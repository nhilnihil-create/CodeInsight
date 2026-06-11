/*
 * じょえチャンネル
 * 高評価・チャンネル登録よろしくおねがいします！
 * https://www.youtube.com/channel/UCRXsI3FL_kvaVL9zoolBfbQ
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define inf (int)(3e18)
#define P pair<int,int>
#define mod (int)(1e9+7)
template<class T> inline void chmin(T &a, T b) {
	a = min(a, b);
}
template<class T> inline void chmax(T &a, T b) {
	a = max(a, b);
}

struct BIT {
	vector<int> bit;
	int n;
	BIT(int x) {
		bit.resize(x + 1, 0);
		n = x;
	}
	void add(int x, int y) {
		while (x <= n) {
			bit[x] += y;
			x += x & -x;
		}
	}
	int sum(int x) {
		int res = 0;
		while (x > 0) {
			res += bit[x];
			x -= x & -x;
		}
		return res;
	}
};

int N,A[100005];
struct info{
	int type,ind,x;
	bool operator<(const info&a)const{
		if(x!=a.x)return x>a.x;
		return type<a.type;
	}
	info(int type,int ind,int x):type(type),ind(ind),x(x){}
};
int ans[100005];
vector<info>q;
signed main(){
	cin>>N;
	int now=0;
	rep(i,N){
		cin>>A[i];
		q.emplace_back(0,i,A[i]);
		if(now<A[i]){
			q.emplace_back(1,i,now);
			now=A[i];
		}
	}
	sort(all(q));
	BIT bit(N),bit2(N);
	int memo=0;
	for(info i:q){
		if(!i.type){
			bit.add(i.ind+1,i.x);bit2.add(i.ind+1,1);
		}
		else {
			int p=bit.sum(N)-bit.sum(i.ind);
			int q=bit2.sum(N)-bit2.sum(i.ind);
			ans[i.ind]=p-i.x*q-memo;
			memo+=ans[i.ind];
		}
	}
	rep(i,N)cout<<ans[i]<<endl;
}
