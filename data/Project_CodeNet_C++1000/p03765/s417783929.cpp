#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pi;
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

const int maxn = 100010;

string S,T;
int AS[maxn], BS[maxn];
int AT[maxn], BT[maxn];
int q;

pi trans(pi a) {
	return pi((a.f - 1 + 3) % 3, (a.s + 2) % 3);
}

int main() {
	FAST
	cin >> S >> T >> q;
	for (int i =1;i<=S.length();i++) {
		AS[i] = AS[i-1];
		BS[i] = BS[i-1];
		if (S[i-1] == 'A') AS[i]++;
		else if (S[i-1] == 'B') BS[i]++; 
	}
	
	for (int i =1;i<=T.length();i++) {
		AT[i] = AT[i-1];
		BT[i] = BT[i-1];
		if (T[i-1] == 'A') AT[i]++;
		else if (T[i-1] == 'B') BT[i]++;
	}
	
	for (int i =0;i<q;i++) {
		int a,b,c,d; cin >> a >> b >> c >> d;
		pi og = pi((AS[b] - AS[a-1])%3, (BS[b] - BS[a-1])%3);
		pi tcount = pi((AT[d] - AT[c-1])%3, (BT[d] - BT[c-1])%3);
		if (og == tcount) {
			cout << "YES\n";
			continue;
		}
		//~ cout << "OG: " << og.f << " " << og.s << "\n";
		pi newv = trans(og);
		bool works = false;
		while (newv != og) {
			//~ cout << newv.f << " " << newv.s << "\n";
			if (newv == tcount) {
				cout << "YES\n";
				works = true;
				break;
			}
			newv = trans(newv);
		}
		if (!works) cout << "NO\n";
	}
	
}
