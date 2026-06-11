#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define int long long
#define double long double
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
using namespace std;

signed main(){
    int a,b,c,d,e,f,g; cin>>a>>b>>c>>d>>e>>f>>g;
    if (a == 1 && d == 1 && e == 1)cout << 3 + b << endl;
    else if (a < 2 && d < 2 && e < 2)cout << b << endl;
    else if ((a % 2 == 1 && d % 2 == 1 && e % 2 == 1) || (a % 2 == 0 && d % 2 == 0 && e % 2 == 0))cout << a + b + d + e << endl;
    else cout << a + b + d + e - 1 << endl;
    getchar(); getchar(); return 0;
}
