#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main(){ _

	pii S,F;
	cin >> S.f >> S.s;
	cin >> F.f >> F.s;

	string go = "", r_go;

	if(S > F) swap(S,F);

	int dx = F.f - S.f;
	int dy = F.s - S.s;

	while(dy--) go += 'U';
	while(dx--) go += 'R';

	r_go = go;

	for(auto &x : r_go){
		if(x == 'U') x = 'D';
		if(x == 'R') x = 'L';
	}

	cout << go << r_go;
	cout << "LU" << go << "RDRD" << r_go << "LU" << endl;

	return 0;
}
