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

	int a,b,c;
	cin >> a >> b >> c;

	multiset<int> S;
	S.insert(a);
	S.insert(c);
	S.insert(b);

	if(S.count(5) == 2 && S.count(7) == 1)
		cout << "YES\n";
	else cout << "NO\n";

	return 0;
}
