#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,a,b;cin >> n >> a >> b;
	vector<ll> h(n);
	rep(i,n) cin >> h.at(i);
	ll l=0,r=1000000000;
	while(r-l>1){
		ll mid=(r+l)/2,sum=0;
		rep(i,n){
			if(h.at(i)>mid*b) sum+=(h.at(i)-mid*b+(a-b-1))/(a-b);
		}
		if(sum<=mid) r=mid;
		else l=mid;
	}
	cout << r << endl;
}