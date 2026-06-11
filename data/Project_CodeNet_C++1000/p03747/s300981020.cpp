#include <bits/stdc++.h>
//#include <math.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<ll,int> P;
typedef pair<ll,P> PP;

//-----------------------------------------------------------------------------

int n;
ll length,timelimit,first_pos[100000],last_pos[100000];
int dir[100000];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>n>>length>>timelimit;
	REP(i,n) cin>>first_pos[i]>>dir[i];

	REP(i,n) {
		if(dir[i]==1) last_pos[i]=(first_pos[i]+timelimit%length)%length;
		else last_pos[i]=(first_pos[i]-timelimit%length+length)%length;
	}

	int round_times=0,rest_times=0;
	FOR(i,1,n) {
		if(dir[0]!=dir[i]) {
			round_times+=2;
			if(dir[0]==1) {
				if(first_pos[i]-first_pos[0]<=timelimit%length*2) rest_times++;
				if(first_pos[i]-first_pos[0]+length<=timelimit%length*2) rest_times++;
			}
			else {
				if(length-first_pos[i]+first_pos[0]<=timelimit%length*2) rest_times++;
				if(length-first_pos[i]+first_pos[0]+length<=timelimit%length*2) rest_times++;
			}
		}
	}
	rest_times%=n;

	int	times=(round_times*(timelimit/length)+rest_times)%n;

	ll zero_pos=last_pos[0];
	sort(last_pos,last_pos+n);
	int idx=lower_bound(last_pos,last_pos+n,zero_pos)-last_pos;

	//cout<<"idx="<<idx<<",zero_pos="<<zero_pos<<endl;

	if(dir[0]==1&&idx+1<n&&last_pos[idx]==last_pos[idx+1]) idx++;

	if(dir[0]==1) idx=(n-times+idx)%n;
	else idx=(n+times+idx)%n;

	//cout<<"idx="<<idx<<",times="<<times<<",round="<<round_times<<",rest="<<rest_times<<endl;

	REP(i,n) cout<<last_pos[(i+idx)%n]<<endl;

	return 0;
}
