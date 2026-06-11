#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
#define pq priority_queue
#define P pair<int,int>
#define P2 pair<int,P>
#define P3 pair<int,P2>
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};
const ll LINF=1e18;
const ld PI=abs(acos(-1));
int n;

int main(){
	cin >> n;
	
	REP(i,1,10000){
		if(n<i*(i+1)/2){
			int pos=i*(i+1)/2-n;
			REP(j,0,i) if(j+1!=pos) cout << j+1 << endl;
			break;
		}
	}
	return 0;
}
