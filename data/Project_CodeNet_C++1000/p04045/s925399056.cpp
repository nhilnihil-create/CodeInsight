#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1e6+5;
vector<ll> V;
int pre[maxn];
int has[maxn][10];
int main() {
	for(int i=1;i<maxn;i++)
		for(int j=0;j<10;j++)
			has[i][j]=has[i/10][j]|(i%10==j?1:0);
	int n,k;cin>>n>>k;
	for(int i=1;i<=k;i++) {
		int x;cin>>x;V.push_back(x);
	}
	for(int i=n;;i++) {
		bool ok=1;
		for(auto x:V) {
			if(has[i][x]) {ok=0;break;}
		}
		if(ok) return 0*printf("%d\n",i);
	}    
    return 0;
}