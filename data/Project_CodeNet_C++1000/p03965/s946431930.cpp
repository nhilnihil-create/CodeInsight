#include "bits/stdc++.h"

using namespace std;

//using Matrix = vector< vector<int> >;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9 + 10;
//const ll INF = 1e18 + 10LL;
int dx[5] = {0, 0, 1, -1, 0}, dy[5] = {1, -1, 0, 0, 0};
const double EPS = 1e-10;
bool cmp(P a, P b) { return a.second < b.second; } //End sort (Interval scheduling problem)
ll MOD = 1e9 + 7;

string s;

int pa, gu;
int ans;

int main(void){
	cin>>s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'g') {
			if (pa + 1 <= gu) {
				ans++;
				pa++;
			} else {
				gu++;
			}
		}
		else {
			if (pa + 1 <= gu) pa++;
			else {
				gu++;
				ans--;
			}
		}
	}

	printf("%d\n", ans);
	
	return 0;
}