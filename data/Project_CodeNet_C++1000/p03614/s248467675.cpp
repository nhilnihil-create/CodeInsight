#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1e5;
int N,p[MAX_N];
int main(){
	cin>>N;
	REP(i,N){
		cin>>p[i];
	}
	int ans=0;
	REP(i,N){
		if(p[i]==i+1){
			ans++;
			i++;
		}
	}
	cout<<ans<<endl;
	return 0;
}