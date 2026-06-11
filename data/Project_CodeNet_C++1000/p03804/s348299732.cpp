#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	int n,m;
	bool is=false;
	cin >>n>>m;
	vector<string>a(n),b(m);
	rep(i,n){
		cin>>a[i];
	}
	rep(i,m){
		cin>>b[i];
	}
	bool can=true;
	for(int i=0;i<=n-m;i++){
	
		for(int j=0;j<=n-m;j++){
			can = true;
		//	clog << i << " " << j << endl;
			rep(I,m){
				
			can&=(equal(b[I].begin(),b[I].end(),(a[i+I].begin())+j));
			//clog<<I<<" "<<can<<endl;
			}
			if (can)
			{
				is = true;
			}
		}
	
	}
	cout<<solve(is)<<endl;
}