#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define ll long long 
//#define int long long
#define ld long double
#define vi deque<int>
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define iii pair<int,ii>
#define il pair<int,ll>
#define pll pair<ll,ll>
#define _path pair<ll,pair<ll,int> > 
#define vv deque
//#define endl '\n'
//#define mp make_pair

using namespace std;

const int MAXN = 1+5;
const int MOD = 1e9+7;

void solve(){
	int n;
	cin >> n;
	string s1,s2;
	cin >> s1 >> s2;
	ll tot = 1;
	int last = -1;
	FOR(i,n){
		if(last == -1){
			if(s1[i] == s2[i]){
				tot *= 3;
				last = 1; // col
			}else{
				i++;
				tot *= 6;
				last = 2; // row
			}
		}else if(last == 1){
			if(s1[i] == s2[i]){
				tot *= 2;
				tot %= MOD;

			}else{
				i++;
				tot *= 2;
				tot %= MOD;
				last = 2;
			}
		}else{
			if(s1[i] == s2[i]){
				last = 1;
			}else{
				i++;
				tot *=3;
				tot %= MOD;

			}
		}
		tot %= MOD;
	}
	cout << tot%MOD << endl;
}

void test(int x){
	x += MOD*2;
	while(x > 1){
		FORE(i,2,x){
			if(x%i == 0){
				cout << i <<  " " ;
				x /= i;
				break;
			}
		}
		cout << endl;
	}
}



/*
void solve3(){
	int n;
	cin >> n;
	int arr[3*n];
	FOR(i,3*n)cin >> arr[i];
	ll pref[3*n];
	ll suf[3*n];
	// phase1;
	ll sum = 0;
	set<int> s;
	FOR(i,3*n){
		s.insert(arr[i]);
		s += arr[i];
		if(s.size() > n){
			s -= *(s.begin());
			s.erase(s.begin());
		}
		if(s.size() == n){
			pref[i] = sum;
		}else{
			pref[i] = 0;
		}
	}
	// pahse 2;
	sum = 0;
	s.clear();
	for(int i = 3*n-1;i>=0;i--){
		s.insert(-arr[i]);
		s += arr[i];
		if(s.size() > n){
			s += *(s.begin());
			s.erase(s.begin());
		}
		if(s.size() == n){
			pref[i] = sum;
		}else{
			pref[i] = 0;
		}
	}

}*/

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	test(958681902);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}