#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define rrep(i,j,n) for(ll i = (ll)(j); i < (ll)(n); i++)
#define mrep(i,n) for (ll i = (ll)(n-1); i > 0; i--)
#define be(v) (v).begin(), (v).end()
#define scout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	int n,a,b; cin >> n >> a >> b;
	string s; cin >> s;
	int k=a+b;
	int A=0;
	int B=0;
	rep(i,n) {
		if(s[i]=='c') cout << "No" << endl;
		else if(s[i]=='a') {
			if(A+B>=k) cout << "No" << endl;
			else {
				cout << "Yes" << endl;
				A++;
			}
		}
		else if(s[i]=='b') {
			if(A+B>=k) cout << "No" << endl;
			else if(b<=B) cout << "No" << endl;
			else {
				cout << "Yes" << endl;
				B++;
			}
		}
	}
}