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
	int n,m;
	cin >> n >> m;
	string a[n];
	string b[n];
	int s;
	bool ans=false;
	FOR(i,n) cin >> a[i];
	FOR(i,m) cin >> b[i];
	FOR(i,n-m+1)
		FOR(j,n-m+1)
			{
				int k=0;
				while(k<m){
				if(a[j+k].substr(i,m)!=b[k]) { break;}
				k++;
				}
				if(k==m) {ans=true; break; }
			}
	if(ans)cout << "Yes";
	else cout << "No";

	return 0;
}