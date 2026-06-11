#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define pb push_back
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
const int MOD = 1e9+7;

int main() {
	string s;
  	cin >> s;
  	int n = s.size();
  	char first,end;
  	first = s[0];
  	end = s[n-1];
  	int i = n-2;
  	cout << first << i << end << endl;
}