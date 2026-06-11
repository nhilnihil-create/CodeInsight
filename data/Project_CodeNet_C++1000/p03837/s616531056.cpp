#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type_a,class Type_b> bool chmax(Type_a &a,const Type_b &b){if(a<b){a=b;return true;}return false;}
template<class Type_a,class Type_b> bool chmin(Type_a &a,const Type_b &b){if(a>b){a=b;return true;}return false;}
template<class Type> Type igcd(Type x,Type y){if(x==0||y==0)return (x>y)?x:y;return (y%x)?igcd(y%x,x):x;}
template<class Type> Type ilcm(Type x,Type y){return x/igcd(x,y)*y;}
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cout<<' ';cout<<elem;}cout<<endl;}

int main(){
	int n,m;
	cin>>n>>m;
	
	vi a(m),b(m),c(m);
	vvi d(n,vi(n,INF));
	REP(i,m){
		cin>>a[i]>>b[i]>>c[i];
		a[i]--, b[i]--;
		d[a[i]][b[i]]=d[b[i]][a[i]]=c[i];
	}
	
	REP(k,n)REP(i,n)REP(j,n){
		chmin(d[i][j],d[i][k]+d[k][j]);
	}
	
	int ans=0;
	REP(i,m){
		if(c[i]>d[a[i]][b[i]]) ans++;
	}
	
	cout<<ans<<endl;
}