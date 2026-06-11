#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz size()
#define pb(x) push_back(x) 
#define bg begin()
#define ed end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define mp(x,y) make_pair(x,y)
const ll MOD=1000000007;

ll maxx(ll x,ll y,ll z){
	return max(max(x,y),z);
}
ll minn(ll x,ll y,ll z){
	return min(min(x,y),z);
}
ll gcd(ll x,ll y){
	if(x%y==0) return y;
    else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
	return x*(y/gcd(x,y));
}

//a,b x
int main(){
	ll N,W; cin>>N>>W;
	vector<P> p(N);
	ll X[4]={1,0,0,0};

	ll A,B; cin>>A>>B;
	p[0]=mp(A,B);
	ll w1=p[0].a;
	for(int i=1;i<N;i++){
		ll A,B; cin>>A>>B;
		if(A==w1) X[0]++;
		else if(A==w1+1) X[1]++;
		else if(A==w1+2) X[2]++;
		else X[3]++;

		p[i]=mp(A,B);
	}
	sort(p.bg,p.ed);

	ll ans=0;
	for(int i=0;i<=X[0];i++){
		for(int j=0;j<=X[1];j++){
			for(int k=0;k<=X[2];k++){
				for(int l=0;l<=X[3];l++){
					//重量オーバーについて
					if(w1*i+(w1+1)*j+(w1+2)*k+(w1+3)*l<=W){
						ll value=0;
						for(int q=X[0]-1;q>=X[0]-i;q--) value+=p[q].b;
						for(int w=X[0]+X[1]-1;w>=X[0]+X[1]-j;w--) value+=p[w].b;
						for(int e=X[0]+X[1]+X[2]-1;e>=X[0]+X[1]+X[2]-k;e--) value+=p[e].b;
						for(int r=X[0]+X[1]+X[2]+X[3]-1;r>=X[0]+X[1]+X[2]+X[3]-l;r--) value+=p[r].b;

						ans=max(ans,value);
					}
				}
			}
		}
	}
	cout<<ans;
}