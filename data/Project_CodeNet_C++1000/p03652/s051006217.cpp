#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<" = "<<x<<endl;
#define dbg_v(v,n) {cerr<<#v<<" = [";for(int III=0;III<=n;III++)cerr<<v[III]<<(III!=n?",":"]\n");}
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define MOD 1000000007
#define zeros(x) x&(x-1)^x
#define fi first
#define se second
#define Nmax 505
using namespace std;

int n,m,mat[Nmax][Nmax],v[Nmax];
int fr[Nmax];

int getAns(int &bst){
	memset(fr, 0, sizeof(fr));
	for (int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if (v[mat[i][j]]){
				fr[mat[i][j]]++;
				break;
			}
		}
	}
	int mx = 0;
	for (int i=1;i<=m;i++){
		if (fr[i] > mx){
			mx = fr[i];
			bst = i;
		}
	}
	return mx;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
    	for (int j=1;j<=m;j++){
    		cin >> mat[i][j];
    	}
    }
    for (int i=1;i<=m;i++) v[i] = 1;

    int ans = 1e9;
    for (int i=1;i<=m;i++){
    	int bst;
    	ans = min(ans, getAns(bst));
    	v[bst] = 0;
    }

    cout << ans << '\n';
    return 0;
}