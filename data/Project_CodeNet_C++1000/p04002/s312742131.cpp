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
ll h,w,n,a,b;

int main(){
	cin >> h >> w >> n;
	
	map<P, int> mp;
	REP(q,0,n){
		cin >> a >> b; a--; b--;
		REP(i,max(0LL,b-2),min(w-3,b)+1){
			REP(j,max(0LL,a-2),min(h-3,a)+1){
				mp[P(i,j)]++;
			}
		}
	}
	
	ll pos[20]={};
	for(auto s:mp){
		pos[s.second]++;
		pos[0]++;
	}
	
	pos[0]=(h-2)*(w-2)-pos[0];
	REP(i,0,10) cout << pos[i] << endl;
	return 0;
}

