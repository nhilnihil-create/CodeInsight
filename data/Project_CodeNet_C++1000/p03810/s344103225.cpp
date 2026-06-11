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
int n,a[100010];

int gcd(int a,int b){
	if(b) return gcd(b,a%b);
	else return a;
}

int solve(){
	int c=0;
	REP(i,0,n) c+=a[i]%2;
	if((n-c)%2==1) return 1;
	if(c>1) return 0;
	REP(i,0,n){
		if(a[i]%2&&a[i]!=1) a[i]--;
		else if(a[i]==1) return 0;
	}
	int g=a[0];
	REP(i,0,n) g=gcd(g,a[i]);
	REP(i,0,n) a[i]/=g;
	
	return !solve();
}
		
int main(){
	cin >> n;
	REP(i,0,n) cin >> a[i];
	
	cout << (solve()?"First":"Second") << endl;
	return 0;
}
