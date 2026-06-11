#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
int a[3][3],n;
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;

int main (){
	string s;
	cin >> s;
	ll cnt=0,len;
	rep (i,s.size()){
		if (s[i]=='A'){
			len = i;
			break;
		}
	}
	ll ans,max1 = -1;
	for (ll i = len;i < s.size();i++){
		cnt++;
		if (s[i]=='Z'){
			max1 = max(max1,cnt);
		}

	}
	cout << max1 << endl;
}


