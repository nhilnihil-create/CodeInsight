#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define REP(i,j) for(int i=1;i<=j;i++)
#define FORN(i,j,k) for(int i=j;i<k;i++)
#define vi vector<int>
#define vvi vector<vi >
#define pii pair<int,int>
#define vpii vector<pii >
using namespace std;
int n;
pii p[100005];
int main(void){
	cin>>n;
	REP(i,n){
		int a;
		cin>>a;
		p[i]=mp(a,i);
	}
	sort(p+1,p+n+1);
//	REP(i,n)cout<<p[i].fi<<' '<<p[i].se<<endl;
	int cnt=0;
	REP(i,n){
		if(i%2!=p[i].se%2){
			cnt++;
//			cout<<p[i].fi<<' '<<p[i].se<<' '<<i<<endl;
		}
	}
	cout<<cnt/2;
	return 0;
} 