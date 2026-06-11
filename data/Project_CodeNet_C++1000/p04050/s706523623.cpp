#include<vector>
#include<algorithm>
#include<set>
#include<iostream>

using namespace std;

const int MX = 100005;

typedef long long ll;
typedef pair<int,int> pii;

int D[MX];
int N, M;

int main()
{
	scanf("%d%d", &N, &M);
	if( N == 1 ) return !printf("1\n1\n1\n");
	if( M == 1 ) return !printf("%d\n2\n%d 1\n", N, N-1);
	if( N == 2 ) return !printf("1 1\n1\n2\n", N);
	
	int tot = N/2;
	for(int i = 1; i <= M; i++) scanf("%d", D+i), tot += D[i]/2;
	if( tot < N-1 ) return !printf("Impossible\n");
	else{
		int a = -1, b = -1;
		for(int i = 1; i <= M; i++){
			if( D[i]%2 == 1 && a == -1 ) a = i;
			else if( D[i]%2 == 1 ) b = i;
		}
		if( a != -1 ) swap(D[1], D[a]);
		if( b != -1 ) swap(D[M], D[b]);
		for(int i = 1; i <= M; i++) printf("%d ", D[i]);
		printf("\n");
		if( D[M] == 1 ){
			printf("%d\n", M-1);
			printf("%d ", D[1]+1);
			for(int i = 2; i <= M-2; i++) printf("%d ", D[i]);
			printf("%d\n", D[M-1]);
		}
		else{
			printf("%d\n", M);
			printf("%d ", D[1]+1);
			for(int i = 2; i <= M-1; i++) printf("%d ", D[i]);
			printf("%d\n", D[M]-1);
		}
	}
}
