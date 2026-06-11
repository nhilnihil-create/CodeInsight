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
	int a,b,n; cin>>a>>b>>n;
	vvi ans(a,vi(b));
	queue<int> q;
	rep(i,0,n){
		int c;
		cin>>c;
		q.push(c);
	}
	//cout<<endl;
	int cnt=1;
	pair<int,int> z=pair<int,int>(0,0);
	while(!q.empty()){
		int c=q.front(); q.pop();
		rep(i,0,c){
			int x=z.first;
			int y=z.second;
			ans[x][y]=cnt;
			if(x%2==0){
				if(y==b-1) z=pair<int,int>(x+1,y);
				else z=pair<int,int>(x,y+1);
			}
			else{
				if(y==0) z=pair<int,int>(x+1,y);
				else z=pair<int,int>(x,y-1);
			}
		}
		cnt++;
	}
	rep(i,0,a){
		rep(j,0,b){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	
		
	return 0;
}