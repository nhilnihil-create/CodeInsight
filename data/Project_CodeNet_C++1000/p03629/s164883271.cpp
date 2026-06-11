#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
typedef long long int ll;
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define si(n) fscanf(in,"%d",&n)
#define NM 200005
#define MOD 1000000007
#define INF 0x7fffffff
//FILE *in=fopen("input.txt","r"), *out = fopen("output.txt", "w");
FILE *in = stdin, *out = stdout;
using namespace std;

char a[NM];
int n, place[NM][30], len[NM];
void input() {
	fscanf(in, "%s", &a[1]);
	n = strlen(a + 1);
}
void pro() {
	FOR(j, 0, 25) place[n + 1][j] = n + 1;
	for (int i = n; i >= 1; i--) {
		FOR(j, 0, 25) place[i][j] = place[i + 1][j];
		place[i][a[i] - 'a'] = i;

		int MAX = 0;
		FOR(j, 0, 25) MAX = max(MAX, place[i][j]);
		if (MAX == n + 1) len[i] = 0;
		else len[i] = len[MAX + 1] + 1;
	}
	int ans_len = len[1] + 1;
	int i = 1;
	for (int left = ans_len; left >= 1; left--) {
		FOR(j, 0, 25) {
			if (place[i][j] == n + 1 || len[place[i][j] + 1] != left - 1) {
				i = place[i][j] + 1;
				fprintf(out, "%c", j + 'a');
				break;
			}
		}
	}
}
int main() {
	input();
	pro();
	return 0;
}