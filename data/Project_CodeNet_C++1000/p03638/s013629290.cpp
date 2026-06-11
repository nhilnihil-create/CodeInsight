#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 110;







int n, m, c;
int a[maxn*maxn];
int g[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>m>>c;


    for (int i=1; i<=c; i++) {
	cin>>a[i];
    }

    
    for (int i=0; i<n; i++) {
	if (i%2==0) {
	    for (int j=0; j<m; j++) {
		g[i][j]=c;
		if (--a[c] == 0) c--;
	    }
	} else {
	    for (int j=m-1; j>=0; j--) {
		g[i][j]=c;
		if (--a[c] == 0) c--;
	    }
	}
    }


    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    cout<<g[i][j]<<" ";
	}
	cout<<"\n";
    }

    return 0;
}
