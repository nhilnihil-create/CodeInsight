#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#include<cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INF INT_MAX/3
#define REP(i,n) for(int i=0;i<n;i++)
#define show(x) cout<< #x << " = " << (x) << endl
#define show_array(arr) REP(i,int((arr).size()))cout<< #arr << "["<<i<<"]"<<"="<<arr[i]<<endl



int main(){
	
	int W,H;
	cin>>W>>H;
	
	vector<pair<ll,int>> edges;

	REP(i, W+H){
		ll p;
		cin>>p;
		edges.push_back(pair<ll,int>(p,i));
	}


	sort(edges.begin(),edges.end());

	ll A = W+1;
	ll B = H+1;
	ll res = 0;

	for(int i = 0; i  < edges.size(); i++){
		
		if(edges[i].second < W){
			res += edges[i].first * B;
			A--;
		}
		else{
			res += edges[i].first * A;
			B--;
		}
	}
	cout<<res<<endl;
	// vector<vector<ll>> dp(W+1,vector<ll>(H+1,INF));
    //
	// REP(i,W)cin>>arr_p[i];
	// REP(i,H)cin>>arr_q[i];
	//
	// dp[0][0] = 0;
	// REP(i,W){
	// 	dp[i+1][0] = dp[i][0] + arr_p[i];
	// }
	// REP(j,H){
	// 	dp[0][j+1] = dp[0][j] + arr_q[j];
	// }
	// dp[0][1] = arr_q[0];
	// dp[1][0] = arr_p[0];
    //
	// for(ll i = 0; i < W; i++ ){
	// 	for(ll j = 0; j < H; j++){
	// 		dp[i + 1][j + 1] =dp[i+1][j] + dp[i][j+1] - dp[i][j] + min(arr_p[i],arr_q[j]);
	// 	}
	// }
	//
	// cout<<dp[W][H]<<endl;
	return 0;
}
