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

	multiset<char> S;
	string w;
	cin >> w;

	for(int i = 0; i < w.size(); i++){
		S.insert(w[i]);
	}

	int cnt = S.count(w[0]);

	bool can = 1;
	for(auto x : S){
		can &= ((S.count(x) & 1) == 0);
	}
	

	cout << (can ? "Yes" : "No") << endl;


	return 0;
}
