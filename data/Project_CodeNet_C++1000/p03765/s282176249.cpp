#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n,m;
int a[maxn],b[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    string s,t;
    cin>>s>>t;
    n=s.length();
    m=t.length();
    
    for (int i=1; i<=n; i++) {
	a[i] = s[i-1]=='A';
    }

    for (int i=1; i<=m; i++) {
	b[i] = t[i-1]=='A';
    }


    for (int i=1; i<=n; i++) {
	a[i] += a[i-1];
    }

    for (int i=1; i<=m; i++) {
	b[i] += b[i-1];
    }

    int q; cin>>q;

    while (q--) {
	int l,r,i,j;
	cin>>l>>r>>i>>j;

	int X = (r-l+1 - (a[r]-a[l-1])) - (a[r]-a[l-1]);
	int Y = (j-i+1 - (b[j]-b[i-1])) - (b[j]-b[i-1]);

	X%=3;X+=3;X%=3;
	Y%=3;Y+=3;Y%=3;

	if (X==Y) {
	    cout<<"YES\n";
	} else {
	    cout<<"NO\n";
	}
    }
  

    return 0;
}
