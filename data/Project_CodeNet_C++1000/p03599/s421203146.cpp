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
double comp(pair<int,int>at){
	return(100.0*at.S/(double)(at.F+at.S));
}
int main(){
	int a,b,c,d,e,f;
	cin >>a>>b>>c>>d>>e>>f;
	pair<int,int>now=mp(0,0);//water,suger
	pair<int,int>ans=mp(100*a,0);
	double max=comp(mp(100,e));
	for (int ia = 0; ia*a * 100 <= f; ia++)
	{
		for (int ib = 0; (ia*a + ib*b) * 100 <= f; ib++)
		{
			now.F = (ia*a + ib*b) * 100;
			if (now.F == 0)
			{
				break;
			}
			for (int ic = 0; now.F + ic*c <= f; ic++){
				for (int id = 0; now.F + ic*c + id*d <= f; id++){
					now.S =ic*c+ id*d;
					if (comp(now) > max)
					{
						break;
					}
					if (comp(now) > comp(ans))
					{
						ans = now;
					}
				}
			}
		}
	}
	cout<<ans.F+ans.S<<" "<<ans.S<<endl;
}