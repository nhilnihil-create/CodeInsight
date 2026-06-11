#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	string s;
	cin >> s;
	if(s.size() < 4){
		cout << "No" << endl;
		return 0;
	}
	const string YAKI = "YAKI";
	for(int i = 0; i < 4; ++i){
		if(YAKI[i] != s[i]){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}

