#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

bool ask(ll N)
{
	cout << "? " << N << "\n";
	fflush(stdin);
	char c;
	cin >> c;
	return c=='Y';
}

int main()
{
    //ios_base::sync_with_stdio(0),cin.tie(0);
    ll t[10];
    t[0] = 1;
    int X = 1;
    for(int i=1; i<=9; i++) t[i] = t[i-1]*10;
    for(int i=1; i<=9; i++){
    	if(ask(t[i])) X++;
    	else break;
    }
    if(X==10){
        for(int i=8; i>=0; i--){
            if(ask(t[i]+1)) continue;
            cout << "! " << t[i+1];
            exit(0);
        }
        cout << "! " << 1;
        exit(0);
    }
    int ans = 0;
    for(int i=X-1; i>=0; i--){
    	int s=0, e=9;
    	if(i==X-1) s = 1;
    	while(s<e){
    		int m = (s+e+1)/2;
    		if(ask((t[i]*m+ans)*10-1)) e = m-1;
    		else s = m;
    	}
    	ans += s*t[i];
    }
    cout << "! " << ans << '\n';
}
