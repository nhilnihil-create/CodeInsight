#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

typedef long long llint;
#define pii pair<int, int>
#define mp make_pair
#define pb push_back

const int INF = 0x3f3f3f3f;
const int N = 305;

int n;
int M[N][N];
int graf[N][N];
bool bio[N][N];

void load( ) {
	cin >> n;
	for( int i = 0; i < n; i++ ) {
		for( int j = 0; j < n; j++ ) {
			cin >> M[i][j];
			graf[i][j] = M[i][j];
		}
	}
}

void solve( ) {
	for( int k = 0; k < n; k++ ) {
		for( int i = 0; i < n; i++ ) {
			for( int j = 0; j < n; j++ ) {
				int ans = graf[i][k] + graf[k][j];
				if( ans <= graf[i][j] ) {
					graf[i][j] = ans;
					if( k != i && k != j ) {
						bio[i][j] = true;
					}
				}
			}
		}
	}
	
	llint sol = 0;
	for( int i = 0; i < n; i++ ) {
		for( int j = 0; j < n; j++ ) {
			if( M[i][j] != graf[i][j] ) {
				printf( "-1\n" );
				return;
			}
			if(!bio[i][j]) sol += graf[i][j];
		}
	}
	
	cout << sol / 2 << endl;
}


int main( void ) {
	load();
	solve();
	return 0;
}
