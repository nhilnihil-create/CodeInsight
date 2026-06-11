#include<bits/stdc++.h>
 
#define INF 1000010000
#define nl '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pdd pair<double,double>
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define sz(c) (c).size()
#define rep(i,n) for( int i = 0; i < n; ++i )
#define repi(i,n) for( int i = 1 ; i <= n; ++i )
#define repn(i,n) for( int i = n - 1 ; i >= 0 ; --i )
#define repf(j,i,n) for( int j = i ; j < n ; ++j )
#define die(s) {std::cout << s << nl;}
#define dier(s) {std::cout << s; return 0;}
#define vi vector<int>
typedef long long ll;
 
using namespace std;
 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 
	cout.setf(ios::fixed);
 
	vi d;
	
	rep(kk , 10){
		int l = (kk ? 0 : 1) , r = 9;
		while(r - l > 1){
			int mid = (r + l) / 2;
			cout << flush << "? ";
			rep(i , 12){
				cout << (i < sz(d) ? d[i] : (i == sz(d) ? mid : 9));
			}
			cout << nl << flush;
			string ans;
			cin >> ans;
			if(ans == "Y"){
				r = mid;
			}else{
				l = mid;
			}
		}
		string ans;

		if(l == 0 && r == 1 && kk == 0){
			d.pb(1);
		}else{
			cout << flush << "? ";
			rep(i , 12){
				cout << (i < sz(d) ? d[i] : (i == sz(d) ? l : 9));
			}
			cout << nl << flush;
			cin >> ans;
			if(ans == "Y")r = l;
			d.pb(r);
		}
	//	if(kk == 8)break;
		cout << flush << "? ";
		if(d[0] == 1){
			rep(i , sz(d))cout << 9;
			cout << nl << flush;
			cin >> ans;
			if(ans == "Y"){
				break;
			}
		}else{
			cout << to_string((ll)pow(10 , sz(d))) << nl << flush;
			cin >> ans;
			if(ans == "N"){
				break;
			}
		}
	}
	cout << flush << "! ";
	for(int e : d)cout << e;
 
	return 0;
}