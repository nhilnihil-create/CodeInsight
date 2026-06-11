#include <bits/stdc++.h> 

using namespace std;

#define fcout(d) cout << fixed << setprecision(d)
#define rep(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define rep1(i,n) for(int (i) = 1; (i) <= (n); ++(i))
#define repU(i,bottom,ceiling) for(auto (i) = (bottom); (i) <= (ceiling); ++(i))
#define repD(i,ceiling,bottom) for(auto (i) = (ceiling); (i) >= (bottom); --(i))
#define repS(s,n) for(int (s) = 0; s < 1 << (n); ++(s))
#define repV(i,v) for(auto (i) = begin(v); (i) < end(v); ++(i))
#define all(v)  begin(v),end(v)
#define clr(v) fill(all(v),0)
#define l_bnd lower_bound
#define u_bnd upper_bound
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define divceil(n,d) ((n)/(d) + ((n)%(d) > 0))
#define parity(a,b) (((a) & 1LL)^((b) & 1LL)^1LL)

typedef long long ll;
typedef unsigned long long ull;
typedef double db;

const pair<int,int> DIR[] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const int INF = -1 + (1 << 30);
const int MOD = (int)1e9 + 7;

ull next_subset(ull subset){
	ull tem = subset + (subset & -subset);
	ull btm = (~tem & subset) / (subset & -subset) >> 1;
	return btm | tem;
}


int N,a[300001];
ll sl[100001],sr[100001];

void solve(){
	
	priority_queue<int,vector<int>,greater<int>> lpq;
	priority_queue<int> rpq;
	
	sl[0] = sr[0] = 0;
	rep(i,N){
		sl[0] += a[i];
		sr[0] += a[N*3-1-i];
		lpq.push(a[i]);
		rpq.push(a[N*3-1-i]);
	}
	
	
	rep(i,N){
		int t = lpq.top();
		if(t > a[i+N]) sl[i+1] = sl[i];
		else{
			lpq.pop();
			lpq.push(a[i+N]);
			sl[i+1] = sl[i] + a[i+N] - t;
		}
	}
	
	rep(i,N){
		int t = rpq.top();
		if(t < a[N*2-1-i]) sr[i+1] = sr[i];
		else{
			rpq.pop();
			rpq.push(a[N*2-i-1]);
			sr[i+1] = sr[i] + a[N*2-i-1] - t;
		}
	}
	
	ll score = -(1LL << 62);
	rep(i,N+1) score = max(score, sl[i] - sr[N-i]);
	cout<<score<<endl;

	return;
}

void input(){
	
	cin>>N;
	rep(i,N * 3) cin>>a[i]; 
	
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	input();
	solve();
	
	return 0;
}



