/*
ID: anonymo14
TASK: wormhole
LANG: C++                 
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int,int>> vpii;

#define F first
#define S second
#define PU push
#define PUF push_front
#define PUB push_back
#define PO pop
#define POF pop_front
#define POB pop_back

#define REP(i,a,b) for(int i=a; i<=b; i++)

#define MOD 1000000007

ll dic(ll a, ll b, ll c) {
	return max(a,max(b,c)) - min(a, min(b,c));
}

void solve(int test_case) {//210
	ll h,w;
	cin>>h>>w;
	ll mn = LONG_MAX;
	for(ll h1=1;h1<=h;h1++) {
		ll a = h1*w, b = ((h-h1)/2)*w, c = w*((h-h1-((h-h1)/2)));
		mn = min(mn,dic(a,b,c));
		a = h1*w, b = ((h-h1))*(w/2);c=(w-(w/2))*((h-h1));
		mn = min(mn, dic(a,b,c));
	}
	for(ll w1=1;w1<=w;w1++) {
		ll a = w1*h, b = ((w-w1)/2)*h, c = h*((w-w1-((w-w1)/2)));
		mn = min(mn,dic(a,b,c));
		a = w1*h, b = ((w-w1))*(h/2);c=(h-(h/2))*((w-w1));
		mn = min(mn, dic(a,b,c));
	}
	cout<<mn;
}

int main() {
	
	////// FILE BASED IO////
	//freopen("wormhole.in", "r", stdin);
	//freopen("wormhole.out", "w", stdout);
	///////////////
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
