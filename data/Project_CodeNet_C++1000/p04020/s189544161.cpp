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
ll n,*dp,*a;

ll func(int i){
	
	if(dp[i]!=-1) return dp[i];
	if(i==0) return (dp[0] = a[i]/2 );
	else if(a[i]%2==0) return (dp[i]= a[i]/2 + func(i-1));
	else {
		if(a[i-1]%2!=0)return (dp[i]=(i>=2)?func(i-2)+(a[i]+a[i-1])/2 :(a[i]+a[i-1])/2 );
		else if(a[i-1]>0) {
			int t=(a[i-1]+a[i])/2;
			a[i-1]=1;
			return (dp[i]=func(i-1)+t);
		}
		else return (dp[i]=func(i-1)+(a[i]+a[i-1])/2);
	}
	//return 0;
}

void solve(){
	dp= new ll[n];
	FOR(i,n)dp[i]=-1;
	a=new ll[n];
	FOR(i,n) cin >> a[i];
	cout << func(n-1);
}

int main(){
	cin >> n;
	solve();

	return 0;
}