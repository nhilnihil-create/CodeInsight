#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
using vi = vector<int>;
const int MOD = 1e9+7;


int main() {
	int a,b,c;
  	cin >> a>> b>> c;
  	if(b-a == c-b) cout << "YES" << endl;
  	else cout << "NO" << endl;
}