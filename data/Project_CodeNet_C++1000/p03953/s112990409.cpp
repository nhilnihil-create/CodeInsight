// Never let them see you bleed...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

ll sm[maxn], ans[maxn];
int p[maxn], pans[maxn];
bool mark[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
	cin >> sm[i];
    }
    for(int i = n; i >= 1; i--){
	sm[i]-= sm[i-1];
    }
    int m;
    ll q;
    cin >> m >> q;
    iota(p, p+n+1, 0);
    for(int i = 0; i < m; i++){
	int pos;
	cin >> pos;
	swap(p[pos], p[pos+1]);
    }
    for(int i = 1; i <= n; i++){
	if(mark[i] == 0){
	    vector<int> vec;
	    int tmp = i;
	    while(!mark[tmp]){
		vec.PB(tmp);
		mark[tmp] = 1;
		tmp = p[tmp];
	    }
	    for(int j = 0; j < sz(vec); j++){
		pans[vec[j]] = vec[(j + q) % sz(vec)];
	    }
	}
    }
    for(int i = 1; i <= n; i++){
	ans[i] = sm[pans[i]];
	ans[i]+= ans[i-1];
	cout << ans[i] << "\n";
    }
    return 0;
}
