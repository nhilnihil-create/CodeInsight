#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T, s;
	cin >> T >> s;

	vector<string> S(T);

	for(int qq = 0; qq < T; qq++){
		cin >> S[qq];
	}

	sort(S.begin(), S.end());
	for(int i = 0; i < T; i++) cout << S[i];

	cout << endl;
	return 0;
}
