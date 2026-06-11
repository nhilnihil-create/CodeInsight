#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)

lli n;
 
bool judge(lli a,lli b,lli c,lli d,lli i){
	lli target = b-a;
	lli plus = i;
	lli minus = n-i-1;
	if(c*plus - minus*d <= target && target <= d*plus - c*minus)return true;
	else return false;
}

signed main(){

	lli a,b,c,d;
	cin>>n>>a>>b>>c>>d;

	for(lli i=0;i<n;i++){
		if(judge(a,b,c,d,i)){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;

	return 0;
}