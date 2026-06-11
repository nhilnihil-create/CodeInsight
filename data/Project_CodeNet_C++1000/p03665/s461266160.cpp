#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

const int MAX_N = 60;
int N, P;
int A[MAX_N];
ll dp[MAX_N][MAX_N];

ll nCk(int n, int k)
{
    return dp[n][k];
}

void solve()
{
    dp[0][0]=1;
    for(int i=1;i<=N;++i) dp[0][i]=0;
    for(int i=1;i<=N;++i) dp[i][0]=1;
    for(int i=1;i<=N;++i)for(int j=1;j<=i;++j){
        dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
    }
	int oc = 0, ec = 0;
	for(int i=0;i<N;++i){
		if(A[i]%2) oc++;
		else ec++;
	}
	ll res = 0;
	if(P == 0){ // even 
		for(int i=0;i<=oc;i+=2){
			for(int j=0;j<=ec;++j){
				res += 1LL*nCk(oc, i)*nCk(ec, j);
			}
		}
	}else{ // odd
		for(int i=1;i<=oc;i+=2){
			for(int j=0;j<=ec;++j){
				res += 1LL*nCk(oc, i)*nCk(ec, j);
			}
		}
	}
	cout<<res<<'\n';
}

int main()
{
	cin >> N >> P;
	for(int i=0;i<N;++i) cin >> A[i];
	solve();
	return 0;
}