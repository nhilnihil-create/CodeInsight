#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 2e5+100;



int n;
string s;

int dp[maxn], dpc[maxn];
int nxt[maxn][26];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>s;
    n=s.length();

    for (int j=0;j<26;j++) {
	nxt[n][j]=n;
	for (int i=n-1; i>=0; i--) {
	    nxt[i][j]=nxt[i+1][j];
	    if (s[i]-'a' == j) {
		nxt[i][j] = i;
	    }
	}
    }


    dp[n+1] = 0;

    for (int i=n; i>=0; i--) {

	dp[i]=1e9;
	dpc[i]=-1;
	
	for (int j=0;j<26;j++) {
	    if (1+dp[nxt[i][j]+1] < dp[i]) {
		dp[i] = 1+dp[nxt[i][j]+1];
		dpc[i] = j;
	    }
	}
    }


    string res;

    for (int j=0; j<n; ) {
	res += char('a'+dpc[j]);
	j = nxt[j][dpc[j]]+1;
    }
    out(res);
    
  
    return 0;
}
