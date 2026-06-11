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



int dp[333][333];

int a[333][333];

bool used[333][333];

int main() {
	
    int n = readInt();
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		cin >> a[i][j];
    		dp[i][j] = a[i][j];
    		if (i == j) {
    			dp[i][j] = MOD;
    		}
    		sum += a[i][j];
    	}
    }
    for (int k = 1; k <= n; k++) {
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= n; j++) {
    		    if (i == j) continue;
    		    if (i == k) continue;
    		    if (k == j) continue;
    			dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
    		} 
    	}
    }
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		if (i == j) continue;
    		if (a[i][j] != dp[i][j]) {
    			cout << -1;
    			return 0;
    		}
    	}
    }

    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
            	if (i == j) continue;
                if (j == k) continue;
                if (i == k) continue;
    			if (!used[i][j] && a[i][j] == a[i][k] + a[k][j]) {
    				sum -= a[i][j];
    				used[i][j] = 1;
    			}
    		}
    	} 
    }
    cout << (sum>>1);
	return 0;
}