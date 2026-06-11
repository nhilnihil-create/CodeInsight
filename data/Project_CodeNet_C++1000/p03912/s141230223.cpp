#include <bits/stdc++.h>
#define FOR(i,a,b) for(ut i=(a);i<(ut)(b);i++)
#define REP(i,b) FOR(i,0,b)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define cat //cout << __LINE__ << endl;
using namespace std;
typedef long long LL;
typedef double ld;
typedef LL ut;
typedef vector<ut> VI;
typedef pair<ut,ut> pr;
typedef pair<ut,pr> ppr;
typedef vector<pr> Vpr;
typedef vector<ppr> Vppr;
typedef priority_queue<pr,Vpr,greater<pr> > PQ;
using namespace std;
const int SIZE=5*1e5;
const LL INF=1LL<<58;
const LL p=1e9+7;
int c[SIZE];
int nums[SIZE];
int doubler[SIZE];
int main(){
	int N,M,x;
	cin >> N >> M;
	REP(i,N){
		cin >> x;
		nums[x%M]++;
		c[x]++;
		if(c[x]%2==0) doubler[x%M]++;
	}
	int ans=0;
	REP(i,M/2+1){
		if(i==0|| i*2==M){
			ans+=nums[i]/2;
			continue;
		}
		ans+=min(nums[i],nums[M-i]);
		int diff=abs(nums[i]-nums[M-i]);
		int number=(nums[i]>nums[M-i])?i:(M-i);
		ans+=min(diff/2,doubler[number]);
	}
	cout << ans << endl;
	return 0;
}