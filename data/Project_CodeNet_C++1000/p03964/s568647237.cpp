#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int main(){
	ll n;
	cin >> n;
	int t[n],a[n];
	FOR(i,n){
		cin >> t[i]>>a[i];
	}
	ll sol=t[0]+a[0];
	ll i=1;
	ll maxt=t[0];
	ll maxa=a[0];
	while(i < n){
		ll j=(sol % (t[i]+a[i])==0 )?sol/(t[i]+a[i]):sol/(t[i]+a[i])+1 ;
		ll j1= (maxt%t[i]==0)? maxt/t[i]:maxt/t[i]+1;
		ll j2= (maxa%a[i] ==0)? maxa/a[i] : maxa/a[i]+1;
		j=max(j,j1);
		j=max(j1,j2);
		
		
		sol=j*(t[i]+a[i]);
		maxt=j*t[i];
		maxa=j*a[i];
		//cout << sol <<" " << maxt <<" "<<maxa<<"\n";
		i++;
	}
	cout << sol;
	return 0;
}
