#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

ll C[42][42];
void init_math(){
	C[0][0] = 1;
	rep1(i,41){
		C[i][0] = 1;
		rep1(j,i){
			C[i][j] = C[i-1][j]+C[i-1][j-1];
		}
		C[i][i+1] = 0;
	}
}
ll f(int n,int m){
	return (1LL<<(n+m-1))-1+C[n+m][n];
}

int main(){
	init_math();
	vector<pair<ll,P>> vec;
	vec.pb(pair<ll,P>(1,P(0,0)));
	for(int n = 1 ; n <= 40 ; n ++){
		for(int m = 1 ; n+m <= 41 ; m ++){
			vec.pb(pair<ll,P>(f(n,m),P(n,m)));
		}
	}
	sor(vec);
	/*ll ret = 0;
	for(int i = 0 ; i+1 < vec.size() ; i ++){
		ret = max( ret , vec[i+1]-vec[i] );
	}
	cout << ret << endl;*/
	
	vector<int> ret;
	
	ll n;
	cin >> n;
	int t = 0;
	
	int W = 2;
	while((1LL<<W)-1 <= n)W ++;
	vector<int> vec_;
	n -= (1LL<<(W-1))-1;
	for(int i = W/2 ; i >= 3 ; i --){
		while(n >= C[W][i]){
			n -= C[W][i];
			vec_.pb(i);
		}
	}
	sor(vec_);
	int loc = 0;
	for(int i = 0 ; i < W ; i ++){
		while(loc < vec_.size() && vec_[loc] == i){
			ret.pb(++loc);
		}
		ret.pb(vec_.size()+1);
	}
	rrep1(i,vec_.size()){
		ret.pb(i);
	}
	t += vec_.size()+1;
	
	//int cnt = 0;
	while(n>0){
		int k = 0;
		while(k+1 < vec.size() && vec[k+1].fr <= n)k ++;
		//cnt += vec[k].sc.fr + vec[k].sc.sc;
		if(vec[k].fr == 1){
			ret.pb(t+1);
			ret.pb(t+1);
			t ++;
		}
		else {
			rep(i,vec[k].sc.fr){
				ret.pb(t+1);
			}
			ret.pb(t+2);
			rep(i,vec[k].sc.sc){
				ret.pb(t+1);
			}
			ret.pb(t+2);
			t += 2;
		}
		n -= vec[k].fr;
		//cout << vec[k].sc.fr << " " << vec[k].sc.sc << endl;
	}
	cout << ret.size() << endl;
	rep(i,ret.size()){
		printf("%d%c",ret[i],(i+1==ret.size())?'\n': ' ');
	}
	//cout << cnt << endl;
}