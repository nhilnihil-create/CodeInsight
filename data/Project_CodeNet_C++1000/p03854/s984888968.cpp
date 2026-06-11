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

	reverse(S.begin(), S.end());
	
	int N = S.size();

	string T = "";

	int l = 0;
	while(l + 2 < N){
	
		string aux = S.substr(l,3);

		if(aux == "res"){
			T += "resare";
			l += 6;
		}
		else if(aux == "esa"){
			T += "esare";
			l += 5;
		}
		else if(aux == "mae"){
			T += "maerd";
			l += 5;
		} 
		else {
			T += "remaerd";
			l += 7;
		}
	}

	if(T == S){
		cout << "YES\n";
	}
	else cout << "NO\n";

	return 0;
}
