#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;

int a[305][305];
bool uzeo[305];

int br[305];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int sol = 1e9;
	for (int i=0 ; i<n ; i++) {
		for (int j=0 ; j<m ; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i=0 ; i<m ; i++) {
		memset(br, 0, sizeof br);
		for (int j=0 ; j<n ; j++) {
			int k = 0;
			for ( ; uzeo[a[j][k]] ; k++) ;
			br[a[j][k]]++;
		}
		int maxx = 0;
		int koji;
		for (int j=1 ; j<=m ; j++) {
			if (br[j] > maxx) {
				maxx = br[j];
				koji = j;
			}
		}
		sol = min(sol, maxx);
		uzeo[koji] = 1;
	}
	printf("%d\n", sol);
	return 0;
}