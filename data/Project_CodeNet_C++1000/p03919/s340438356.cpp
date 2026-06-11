#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<numeric>
#include<limits>
#include<iterator>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,n) for(int i=a; i<n; i++)

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ll, char> plc;

map<int, char> m;

int main()
{	
	int h, w;
	cin >> h >> w;

	int cnt = 0;
	for (char i = 'A'; i <= 'Z'; i++) {
		m[cnt] = i;
		cnt++;
	}

	int ans_i, ans_j;
	rep(i, h) {
		rep(j, w) {
			string s;
			cin >> s;
			if (s == "snuke") {
				ans_i = i + 1;
				ans_j = j;
			}
		}
	}
	cout << m[ans_j] << ans_i << endl;
	return	0;
}


