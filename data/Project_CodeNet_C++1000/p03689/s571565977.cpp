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
int h,w,n,m;

int main(){
	cin >> h >> w >> n >> m;
	
	if((!(h%n))&&(!(w%m))) cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		REP(i,0,h){
			REP(j,0,w){
				if((i%n==n-1)&&(j%m==m-1)) cout << -(n*m-1)*1000-1 << " ";
				else cout << 1000 << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
