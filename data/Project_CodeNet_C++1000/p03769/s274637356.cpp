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
ll n;
vector<int> vec;

int main(){
	cin >> n; int pos=0;
	while((1LL<<pos)-1<=n) vec.push_back(pos),pos++;
	pos--; n-=(1LL<<pos)-1; vec.pop_back();
	
	while(n){
		int c=0;
		while((1LL<<c)<=n) c++; c--;
		vec.insert(vec.begin()+c,pos);
		n-=(1LL<<c); pos++;
	}
	
	cout << vec.size()+pos << endl;
	REP(i,0,vec.size()) cout << vec[i]+1 << " ";
	REP(i,0,pos) cout << i+1 << " "; cout << endl;
	return 0;
}
