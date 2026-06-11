#include <bits/stdc++.h>
using namespace std;

int SA[100009], SB[100009], TA[100009], TB[100009];

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	string S, T; cin >> S >> T;
	int N = S.size(), M = T.size();
	S = "#" + S; T = "#" + T;
	for(int i=1; i<=N; i++) {
		SA[i] = SA[i-1] + (S[i] == 'A');
		SB[i] = SB[i-1] + (S[i] == 'B');
	}
	for(int i=1; i<=M; i++) {
		TA[i] = TA[i-1] + (T[i] == 'A');
		TB[i] = TB[i-1] + (T[i] == 'B');
	}
	int Q; cin >> Q;
	while(Q--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		int SM = (SA[b] - SA[a-1]) - (SB[b] - SB[a-1]);
		int TM = (TA[d] - TA[c-1]) - (TB[d] - TB[c-1]);
		SM += 300000;
		TM += 300000;
		if(SM % 3 == TM % 3) puts("YES");
		else puts("NO");
	}
	return 0;
}