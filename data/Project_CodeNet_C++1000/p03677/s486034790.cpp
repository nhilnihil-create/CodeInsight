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

int main(void){
	ll n,m;
	cin>>n>>m;
	ll a;
	vector<ll> A;
	rep(i,n){
		cin>>a;
		A.push_back(a);
	}

	vector<pair<ll,ll>> kukan;//pair<ll,ll> 左端, 右端
	rep(i,n-1){
		if(A[i] < A[i+1]){
			kukan.push_back(pair<ll,ll>{A[i]+m,A[i+1]+m});
			kukan.push_back(pair<ll,ll>{A[i],A[i+1]});
		}
		else{
          kukan.push_back(pair<ll,ll>{A[i],A[i+1]+m});
          kukan.push_back(pair<ll,ll>{A[i]+m,A[i+1]+m+m});
        }
	}
	sort(all(kukan));

	//pair<ll,ll> : 右端,左端
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> que;
	
	ll val = 0;//現在の明るさtを挟む区間の個数
	int ki = 0;
	ll toku = 0;//お気に入りによって得した量
	ll max_toku = 0;
	rep(t,2*m+3){
		toku += val;
		chmax(max_toku, toku);//明るさtをお気に入りにした時に得した量(手数圧縮量) = toku になってる.
		while(que.size() > 0 && que.top().first == t){
			pair<ll,ll> top = que.top();
			val--;
			toku -= top.first - top.second - 1;//お気に入りがその区間から外れることで, 今まで得とカウントしてた量は無効
			que.pop();
		}
		while(ki < kukan.size() && kukan[ki].first == t){
			que.push(pair<ll,ll>{kukan[ki].second, kukan[ki].first});
			val++;
			ki++;
			toku -= 1;//t+1をお気に入りにしても, まだ得はしないので.
		}
		
		//cout<<toku<<" ";
		//cout<<que.size()<<" ";
	}
	//cout<<endl;
	ll ans = 0;
	rep(i,A.size()-1){//手数圧縮しなかった場合にかかる手数
		if(A[i] < A[i+1]) ans += A[i+1] - A[i];
		else ans += A[i+1] - A[i] + m;
	}
	ans -= max_toku;
	cout<<ans<<endl;
	//cout<<toku<<endl;
	//cout<<max_toku<<endl;
	return 0;
}
