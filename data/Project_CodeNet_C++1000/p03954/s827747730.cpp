/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back

const long long MOD = 1e9 + 7;
const long long MAXN = 1e6 + 1;
using namespace std;

typedef long long ll;

long long readInt() {
    bool minus1 = false;
    long long result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus1 = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus1)
        return -result;
    else
        return result;
}

const int MNN = 333;

int a[MAXN];
int b[MAXN];
//int ans[MNN][MNN];
/*
int get(int a, int b, int c) {
	int sum = a + b + c;
	return sum - min({a, b, c}) - max({a, b, c});
}
*/
int tot;
int n;
bool f(int x) {
	for (int i = 0; i < tot; i++) {
		b[i] = (a[i] <= x ? 1 : 0);
	}
	int kek = n - 1;
	int l = kek;
	int r = kek;
	int dl = 0;
	int dr = 0;
	while(l > 0 && b[l] != b[l - 1]) {
		l--;
		dl++;
	}	
	while(r + 1 < tot && b[r] != b[r + 1]) {
		r ++;
		dr++;
	}
	if (l == 0 && r == tot - 1) {
		return ((n - 1) % 2) ^ b[kek];
	}
	if (dl < dr) {
		return b[l];
	} else {
		return b[r];
	}
}

int main() {
	#ifdef IZI_KATKA
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    n = readInt();
    tot = 2 * n - 1;
    for (int i = 0; i < tot; i++) {
    	a[i] = readInt() - 1;
    }
    int l = 0;
    int r = tot - 1;
	while(l < r) {
		int m = (l + r) / 2;
		if (f(m)) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	cout << l + 1;
    return 0;
}