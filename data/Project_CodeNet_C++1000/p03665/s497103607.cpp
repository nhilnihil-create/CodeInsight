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
int n;
int p;
int* a;



void solve(){
	ll dp[2][n];
	FOR(i,2) FOR(j,n) dp[i][j]=0;
	a=new int[n];
	FOR(i,n) cin >> a[i];
	FOR(j,n)
		FOR(i,2){
			if(j==0){
				if(i==0) dp[i][j]=(a[j]%2==0)? 2: 1;
				else dp[i][j]=(a[j]%2==1) ? 1:0;
			}
			else
			dp[i][j]=(a[j]%2==0)? dp[i][j-1] + dp[i][j-1] : dp[(i+1)%2][j-1]+dp[i][j-1];
		}
	cout << dp[p][n-1];
}

int main(){
	cin >> n >> p;
	solve();

	return 0;
}