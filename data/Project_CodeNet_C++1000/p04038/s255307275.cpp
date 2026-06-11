#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
#include<set>
#include<iostream>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> t3;

const int MX = 2005;
const int MM = 1000000007;

int D[MX][MX];
int F[MX*MX], FI[MX*MX], I[MX*MX];
int N, K;

ll C(int x, int y){
	if( y < 0 || x < y ) return 0;
	return (ll)F[x] * FI[y] % MM * FI[x-y] % MM;
}

int main()
{
	F[0] = FI[0] = I[1] = 1;
	for(int i = 1; i < MX*MX; i++){
		F[i] = (ll)F[i-1] * i % MM;
		if(i>=2) I[i] = (ll)I[MM%i] * (MM - MM/i) % MM;
		FI[i] = (ll)FI[i-1] * I[i] % MM;
	}
	scanf("%d%d", &N, &K); K--;
	if( K == 0 ) return !printf("1\n");
	D[0][0] = 1;
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			if(i) D[i][j] = (D[i][j] + D[i-1][j]) % MM;
			if(j) D[i][j] = (D[i][j] + C(i+j*K-1, K-1) * D[i][j-1]) % MM;
			if( i > j ) D[i][j] = 0;
		}
	}
	printf("%lld\n", D[N][N] * (ll)F[N] % MM);
}
