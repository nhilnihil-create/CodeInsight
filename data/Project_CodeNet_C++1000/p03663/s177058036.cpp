#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 998244353;
constexpr int inf = 3e18;

int mod_pow(int x,int y,int m=mod){
	int res=1;
	while(y>0){
		if(y&1)(res*=x)%=m;
		(x*=x)%=m;
		y>>=1;
	}
	return res;
}
int N;
bool query(int n){
	cout<<"? "<<n<<endl;
	char c;cin>>c;
	return c=='Y';
	/*if(n<=N){
		return to_string(n)<=to_string(N);
	}
	return to_string(n)>to_string(N);*/
}
void answer(int n){
	cout<<"! "<<n<<endl;
	/*if(N!=n){
		assert(0);
	}*/
}
void solve(){
	if(query(mod_pow(10,12,inf))){
		for(int i=10;i>0;i--){
			if(!query(mod_pow(10,i,inf)-1)){
				answer(mod_pow(10,i,inf));
				return;
			}
		}
		answer(1);return;
	}
	rep(i,10){
		if(query(mod_pow(10,i,inf))&&query(mod_pow(10,i+1,inf)-1))
			if(!query((mod_pow(10,i+1,inf)-2)*10)){
					answer(mod_pow(10,i+1,inf)-1);
					return;
			}
	}
	int i=10;
	while(i>=0){
		if(query(mod_pow(10,i,inf))&&query(mod_pow(10,i+1,inf)-1)){
			break;
		}
		i--;
	}
	int ng=mod_pow(10,i,inf)-1,ok=mod_pow(10,i+1,inf)-1;
	while(ok-ng>1){
		int mid=(ok+ng)/2;
		if(query(mid*10))ok=mid;
		else ng=mid;
	}
	answer(ok);
}
signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	/*REP(i,1000){
		N=i;
		solve();
	}*/
	solve();
}
