#include<bits/stdc++.h>
using namespace std;
#define MID (l+r)/2
#define ll long long
typedef pair<ll, ll> ii;
#define S second
#define F first

ll seg[1000000];
ll n, k;

void update(ll p, ll l=0, ll r=n-1, ll ind=1){
	if(l==r && l==p)
		seg[ind]++;
	else if(l==r || p<l || p>r) return;
	else{
		update(p, l, MID, ind*2);
		update(p, MID+1, r, ind*2+1);
		seg[ind] = seg[ind*2] + seg[ind*2+1];
	}
}

ll query(ll rl, ll rr, ll l=0, ll r=n-1, ll ind=1){
	if(rl<=l && r<=rr) return seg[ind];
	else if(rl>r || l>rr) return 0;
	else{
		return query(rl, rr, l, MID, ind*2) + query(rl, rr, MID+1, r, ind*2+1);
	}
}

int main(){
	cin>>n>>k;
	ll a[n];
	ll tot=0;
	ll t[n+1];
	vector<ii> s;
	//s.push_back(ii(0,0));
	for(ll i=0;i<n;i++){
		cin>>a[i];
		tot+=a[i];
		tot-=k;
		t[i] = tot;
		s.push_back(ii(t[i], i));
	}
	sort(s.begin(), s.end());
	ll ans=0;
	for(ll i=s.size()-1;i>=0;i--){
		if(s[i].F>=0) ans++;
		ans += query(s[i].S + 1, n-1);
		update(s[i].S);
	}
	cout<<ans<<endl;
}
