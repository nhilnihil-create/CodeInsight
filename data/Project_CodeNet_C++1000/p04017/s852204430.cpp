#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
#include <set>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()
const int N = 1234567;

ll mpow(ll a, ll b){
	if(b==0) return 1;
	else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%MOD;}
	else return mpow(a,b-1) * a % MOD;
}
ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b, a%b);
}
vector<ll> kaijo_memo;
ll kaijo(ll n){
	if(kaijo_memo.size() > n) return kaijo_memo[n];
	if(kaijo_memo.size() == 0) kaijo_memo.push_back(1);
	while(kaijo_memo.size() <= n) kaijo_memo.push_back(kaijo_memo[kaijo_memo.size()-1] * kaijo_memo.size() % MOD);
	return kaijo_memo[n];
}
ll nCr(ll n, ll r){
	if(n < r || r < 0) return 0;
	ll ret = 1;
	ret *= kaijo(n); ret %= MOD;
	ret *= mpow(kaijo(r), MOD-2); ret %= MOD;
	ret *= mpow(kaijo(n-r), MOD-2); ret %= MOD;
	return ret;
}


int main(void){
	int n;
	cin>>n;
	ll x;
	vector<ll> X;
	//cout<<"hoge"<<endl;
	rep(i,n){
		cin>>x;
		X.push_back(x);
	}
	ll l,q;
	cin>>l;
	vector<vector<ll>> left,right;
	rep(i,n){
		left.push_back(vector<ll>());
		right.push_back(vector<ll>());
		rep(j,20){
			left[i].push_back(-1);
			right[i].push_back(-1);
		}
	}
	//cout<<"hoge"<<endl;
	int li=0,ri=0;
	while(li < n){
		while(ri < n && X[ri] - X[li] <= l){
			ri++;
		}
		while(li < n && (ri == n || X[ri] - X[li] > l)){
			right[li][0] = ri - 1;
			li++;
		}
	}
	//cout<<"hoge"<<endl;

	li=n-1;ri=n-1;
	while(ri >= 0){
		while(li >= 0 && X[ri] - X[li] <= l){
			li--;
		}
		while(ri >= 0 && (li == -1 || X[ri] - X[li] > l)){
			left[ri][0] = li + 1;
			ri--;
		}
	}
	//cout<<"hoge"<<endl;

	reps(j,19){
		rep(i,n){
			right[i][j] = right[right[i][j-1]][j-1];
		}
		REP(i,n){
			left[i][j] = left[left[i][j-1]][j-1];
			//cout<<left[i][j]<<" ";
		}
		//cout<<endl;
	}


	cin>>q;
	rep(i,q){
		ll a,b;
		cin>>a>>b;
		a--;b--;
		ll ans = 0;
		if(a < b){
			while(true){
				int step = 0;
				while(right[a][step+1] < b){
					step++;
				}
				ans += pow(2,step);
				a = right[a][step];
				if(a >= b){
					cout<<ans<<endl;
					break;
				}
				//cout<<step<<endl;
			}

		}else{
			while(true){
				int step = 0;
				while(left[a][step+1] > b){
					step++;
				}
				ans += pow(2,step);
				a = left[a][step];
				
				if(a <= b){
					cout<<ans<<endl;
					break;
				}
				//cout<<step<<endl;
			}
		}
	}

	return 0;
}
