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

	string S;
	cin >> S;

	string s;
	for(int i = 0; i < S.size(); i++){
		if(S[i] == '0'){
			s += '0';
		}
		else if(S[i] == '1'){
			s += '1';
		}
		else{
			if(s.size()) s.pop_back();
		}
		
	}

	cout << s << endl;

	return 0;
}
