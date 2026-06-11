#include <bits/stdc++.h>
using namespace std;
 
#define lli long long int
#define REP(i,s,n) for(lli i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 1
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define TO_STRING(VariableName) # VariableName
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<endl;
#define LOG2(x,y) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<endl;
#define LOG3(x,y,z) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;
#define LOG4(w,x,y,z) if(DEBUG)cout<<TO_STRING(w)<<"="<<w<<" "<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;
 
template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

lli dp[5100][5100];
 
int main(){

	lli n,k;
	cin>>n>>k;

	vector<lli> a(n);
	REP(i,0,n)cin>>a[i];

	sort(a.begin(),a.end());

	lli ans = n;

	dp[0][0]=1;

	REP(i,0,n){
		REP(j,0,k){
			dp[i+1][j] += dp[i][j];
			if(j+a[i] < k){
				dp[i+1][j+a[i]] += dp[i][j];
			}
		}
	}

	REP(i,0,n){
		lli dplast[5100];
		REP(j,0,5100)dplast[j] = dp[n][j];
		//戻すDP
		REP(j,0,k){
			if(j+a[i] < k){
				dplast[j+a[i]] -= dplast[j];
			}
			if(j >= k-a[i] && dplast[j]){
				ans--;
				break;
			}
		}
	}

	cout<<ans<<endl;




    return 0;
}