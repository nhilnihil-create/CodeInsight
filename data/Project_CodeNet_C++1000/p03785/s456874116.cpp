#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	int n, c, k;
	cin >> n >> c >> k;
	int t[n];
	REP(i, 0, n) cin >> t[i];
	
	sort(t, t+n);
	int ans = 0;
	REP(i, 0, n){
		int dep_time = t[i], dep_people=c;
		while(i<n && dep_people > 0 && t[i] <= dep_time + k){
			--dep_people;
			++i;
			//cout << dep_people << " " << i << " " << t[i] << " " << dep_time << " " << dep_time+k<< endl;
		}
		++ans;
		--i;
	}
	cout << ans;

}
