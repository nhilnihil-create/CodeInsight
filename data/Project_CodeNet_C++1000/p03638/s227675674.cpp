#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll H,W;
ll N;
ll a[10005];
ll grid[105][105];

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>H>>W>>N;

rep(i,N) cin>>a[i];

ll color=0;
rep(h,H){
	if(h%2==0){
		rep(w,W){
		grid[h][w]=color+1;
		a[color]--;
		if(a[color]==0) color++;
		}
	}else{
		rep(w,W){
		ll ww=W-1-w;
		grid[h][ww]=color+1;
		a[color]--;
		if(a[color]==0) color++;
		}
	}
}

rep(h,H){
	rep(w,W){
		if(w==W-1) cout<<grid[h][w];
		else cout<<grid[h][w]<<" ";
	}
	cout<<endl;
}

}
	
