#include <bits/stdc++.h>
#define FOR(i,a,b) for(ut i=(a);i<(ut)(b);i++)
#define REP(i,b) FOR(i,0,b)
using namespace std;
typedef long long LL;
typedef LL ut;
const int SIZE=5+1e5;
const LL INF=1<<30;
const LL p=7+(1e9);
LL A[SIZE];
char B[SIZE];
bool isMinus[SIZE];
int main(){
	int N;
	cin >> N;
	LL ans=0;
	cin >> ans;
	REP(i,N-1){
		cin >> B[i];
		cin >> A[i];
		isMinus[i]=B[i]=='-';
	}
	LL freedom=0,needm=0,cost=0;
	REP(j,N-1){
		int i=N-1-j-1;
		cost+=A[i];
		needm+=A[i];
		if(isMinus[i]){
			freedom=max(freedom-A[i],needm-cost*2);
			cost=0;
		}
		else freedom+=A[i];
		
	}
	cout << freedom+ans << endl;
	return 0;
}