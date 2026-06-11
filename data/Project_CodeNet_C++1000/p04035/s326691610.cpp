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
#define solve(a) ((a)?"Possible":"Impossible")
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
	int n,l;
	Vi ans;
	pair<int,ll>up=mp(-1,-1);
	cin >>n>>l;
	V a(n);
	rep(i,n){
		cin>>a[i];
	}
	rep(i,n-1){
		if(chmax(up.S,a[i]+a[i+1])){
			up.F=i;
		}
	}
	cout<<solve(up.S >=l)<<endl;

	if(up.S <l){return 0;}
	ans.push_back(up.F);
	for(int i=up.F+1;i<n-1;i++){
		ans.push_back(i);
	}
	for(int i=up.F-1;i>=0;i--){
		ans.push_back(i);
	}
	reverse(all(ans));
	repi(itr,ans){
		cout<<(*itr)+1<<endl;	}
}