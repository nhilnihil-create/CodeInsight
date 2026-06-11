#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)

int main(){

	lli n;
	cin>>n;

	vector<lli> a(n);
	REP(i,0,n)cin>>a[i];

	lli num = 1;
	lli ans = 0;

	for(lli i=0;i<n;i++){
		if(DEBUG)cout<<"i="<<i<<"a[i]="<<a[i]<<endl;
		if(DEBUG)cout<<"num="<<num<<"ans="<<ans<<endl;
		if(a[i]==num){
			num++;
			continue;
		}
		lli plus = a[i]/num;
		if(a[i]%num==0)plus--;
		ans += plus;
		if(i==0)num++;
	}
	cout<<ans<<endl;

	return 0;
}