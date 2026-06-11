#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;
LL A[100001];
vector<LL>v;
bool check(LL x){
	LL now=0;
	REP(i,x+1){
		now+=v[i];
	}
	for(int i=x+1;i<N;i++){
		//cout<<now<<" "<<v[i]<<endl;
		if(now*2<v[i]){
			return false;
		}else{
			now+=v[i];
		}
	}
	return true;
}
LL binary_search(){
	LL lb=-1;
	LL ub=N;
	while(ub-lb>1){
		LL mid=(ub+lb)/2;
		if(check(mid)==true){
			ub=mid;
		}else{
			lb=mid;
		}
	}
	//cout<<ub<<" "<<lb<<endl;
	return N-1-lb;
}
int main(){
	cin>>N;
	REP(i,N){
		cin>>A[i];
		v.push_back(A[i]);
	}
	sort(v.begin(),v.end());
	//check(0);
	cout<<binary_search()<<endl;
}