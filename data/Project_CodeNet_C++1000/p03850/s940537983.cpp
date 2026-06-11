#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e5 + 100;

int N; ll Dy[3][MAX_N];
int main() {
	int a = 2, b = 2;
	cin >> N;
	
	Dy[1][0] = Dy[2][0] = -LINF;
	for(int i=1; i<=N; i++) {
		char S[9]; if(i > 1) scanf("%s", S);
		int op = (i == 1 ? 1 : (S[0] == '+' ? 1 : -1) );
		int nr; scanf("%d", &nr);

		for(int k=0; k<=2; k++) Dy[k][i] = Dy[k][i-1] + (k%2 == 0 ? nr * op : nr * op * -1);
		for(int k=1; k<=2; k++) Dy[k-1][i] = max(Dy[k-1][i], Dy[k][i-1] + (k%2 == 0 ? nr * op : nr * op * -1));
		if(op == -1) for(int k=0; k<=1; k++) Dy[k+1][i] = max(Dy[k+1][i], Dy[k][i-1] + (k%2 == 0 ? nr * op : nr * op * -1));
	}
	printf("%lld\n", Dy[0][N]);
	return 0;
}
