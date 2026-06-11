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

	string S;
	cin >> S;

	int N = S.size();

	int l = 0;
	for(int i = N - 1; i >= 0; i--)
		if(S[i] == 'A') l = i;

	int r;

	int id = -1;
	for(auto x : S){
		id++;
		if(x == 'Z') r = id;
	}

	cout << r-l + 1 << endl;

	return 0;
}
