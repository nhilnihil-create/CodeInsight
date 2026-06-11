#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<62;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	int n;
	ll x;
	ll ans=0;
	cin >>n>>x;
	V a(n);
	ll bef;
	ll sum=0LL;
	rep(i,n){
		cin>>a[i];
		if(i==0){
			
			ans+=max(0LL,a[0]-x);
			a[0]=min(a[0],x);
			sum=a[0];
		
			//clog<<sum<<" "<<ans<<endl;
		}else{
			sum+=a[i];
			//clog << "(" << sum << ") ";
			bef=sum-x;
			if(bef >0){
				ans+=bef;
			
			if(a[i] >=bef){
				a[i]-=bef;
			}else{
				a[i]=0;
				a[i-1]=bef-a[i];
			}
			}
			sum=a[i]+a[i-1];

			//clog << sum << " " << ans << endl;
			sum-=a[i-1];
		}
	}
	cout<<ans<<endl;
}