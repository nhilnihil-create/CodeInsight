#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define n_p(v) next_permutation(v.begin(),v.end())
#define to_ll(b) stoll(b)
#define MOD 1000000007
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp

signed main(){
	int N; cin>>N;
	vl vec(N);
	rep(i,0,N){
		ll a; cin>>a;
		vec[i]=a;
	}
	sort(all(vec));
	reverse(all(vec));
	ll yoko=0,tate=0;
	rep(i,0,N){
		if(vec[i]==vec[i+1] && vec[i]!=0){
			if(yoko==0){
				yoko=vec[i];
				vec[i]=0;
				vec[i+1]=0;
			}
			else if(tate==0) {
				tate=vec[i];
				vec[i]=0;
				vec[i+1]=0;
			}
		}
		if(yoko!=0 && tate!=0) break;
	}
	cout<<tate*yoko;
	
	return 0;
}