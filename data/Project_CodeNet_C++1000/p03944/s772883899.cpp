#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	int w,h,n; cin>>w>>h>>n;
	int vec[120][120];
	n++;
	while(--n){
		int x,y; cin>>x>>y;
		//--x; --y;
		int type; cin>>type;
		if(type==1){
			rep(i,0,x){
				rep(j,0,h){
					vec[i][j]=1;
				}
			}
		}
		else if(type==2){
			rep(i,x,w){
				rep(j,0,h){
					vec[i][j]=1;
				}
			}
		}
		else if(type==3){
			rep(i,0,w){
				rep(j,0,y){
					vec[i][j]=1;
				}
			}
		}
		else{
			rep(i,0,w){
				rep(j,y,h){
					vec[i][j]=1;
				}
			}
		}
	}
	ll ans=0;
	rep(i,0,w){
		rep(j,0,h){
			if(!vec[i][j]) ans++;
		}
	}
	cout<<ans;
	return 0;
}