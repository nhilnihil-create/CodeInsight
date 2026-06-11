#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e05 + 10;
const int MAXM = 1e05 + 10;

struct LinkedForwardStar {
    int to;

    int next;
} ;

LinkedForwardStar Link[MAXM];
int Head[MAXN]= {0};
int size = 0;

void Insert (int u, int v) {
    Link[++ size].to = v;
    Link[size].next = Head[u];

    Head[u] = size;
}

int N, K;
int add = 1;

// 注意，由下往上必比由上往下合并更优
int cnt = 0;
int DFS (int root, int father, int deep) {
	int maxv = deep;
	for (int i = Head[root]; i; i = Link[i].next) {
		int v = Link[i].to;
		maxv = max (maxv, DFS (v, root, deep + 1));
	}
	if (father!= 1 && maxv - deep == K - 1) {
		cnt ++;
		return 0;
	}
	return maxv;
}

int getnum () {
    int num = 0;
    char ch = getchar ();

    while (! isdigit (ch))
        ch = getchar ();
    while (isdigit (ch))
        num = (num << 3) + (num << 1) + ch - '0', ch = getchar ();

    return num;
}

int main () {
    N = getnum (), K = getnum ();
    for (int i = 1; i <= N; i ++) {
        int v = getnum ();
        if (i == 1 && v == 1) add = 0;
        if (i > 1) Insert (v, i);
    }
    DFS (1, 1, 0);
    int ans = cnt + add;
    printf ("%d\n", ans);

    return 0;
}

/*
3 1
2 3 1
*/

/*
4 2
1 1 2 2
*/

/*
8 2
4 1 2 3 1 2 3 4
*/