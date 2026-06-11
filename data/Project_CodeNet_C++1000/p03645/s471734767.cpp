#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define EPS      (double)1e-9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cout<<' ';cout<<elem;}cout<<endl;}

int main(){
	int n,m;
	cin>>n>>m;
	
	vi s;
	vi g;
	REP(i,m){
		int a,b;
		cin>>a>>b;
		if(a==1) s.push_back(b);
		if(b==n) g.push_back(a);
	}
	sort(ALL(g));
	
	for(auto elem:s){
		if(binary_search(ALL(g),elem)){
			cout<<"POSSIBLE"<<endl;
			return 0;
		}
	}
	
	cout<<"IMPOSSIBLE"<<endl;
}