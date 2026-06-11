#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const long long INF = (1LL<<62);

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int x = 0;
	int N; cin >> N;
	string S; cin >> S;
	int ans = x;
	for(int i=0; i<N; i++){
		if(S[i] == 'I') x++;
		else if(S[i] == 'D') x--;
		if(ans < x) ans = x;
	}
	printf("%d\n", ans);
	return 0;
}