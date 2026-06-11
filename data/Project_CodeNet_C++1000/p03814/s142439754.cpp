#include <bits/stdc++.h>
using namespace std;
#define ar array
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const ll mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
	string s;
	cin >> s;
	char a = 'A', z = 'Z';
	int fst = 0, lst = 0;
	for(int i = 0; i < s.size(); i++)
		if(s[i] == a) {
			fst = i;
			break;
		}
	for(int i = s.size() - 1; i > 0; i--)
		if(s[i] == z) {
			lst = i;
			break;
		}
	cout << lst - fst + 1 << endl;
  	return 0;
}

