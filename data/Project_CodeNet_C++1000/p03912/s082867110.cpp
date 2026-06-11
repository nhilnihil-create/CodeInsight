#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

/*
*/

ll n,m,ans=0;
V<ll> v[100010];

void init(){
	cin>>n>>m;
	rep(i,n){
		ll x;
		cin>>x;
		v[x%m].push_back(x);
	}
	rep(i,m)sort(v[i].begin(),v[i].end());
}

int main(void){
	init();
	reg(i,0,m/2){
		if(i==0 || i*2==m){
			ans+=v[i].size()/2;
			continue;
		}
		if(v[i].size()>v[m-i].size()){
			// v[m-i]を全てv[i]とマッチ
			ll match=0;
			for(int j=0; j<v[i].size()-1 && v[i].size()-v[m-i].size()>=match+2; j++){
				if(v[i][j]==v[i][j+1]){
					match+=2;
					j++;
				}
			}
			ans+=match/2 + v[m-i].size();
		}else{
			// v[i]を全てv[m-i]とマッチ
			ll match=0;
			for(int j=0; j<v[m-i].size()-1 && v[m-i].size()-v[i].size()>=match+2; j++){
				if(v[m-i][j]==v[m-i][j+1]){
					match+=2;
					j++;
				}
			}
			ans+=match/2 + v[i].size();
		}
	}
	cout<<ans<<endl;
	return 0;
}