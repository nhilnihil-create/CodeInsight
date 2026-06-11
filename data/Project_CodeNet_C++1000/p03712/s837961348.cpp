#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int h, w;
    cin >> h >> w;
    
    vector<string> a(h);
    rep(i, h) cin >> a[i];
    
    rep(i, w + 2) cout << "#";
    cout << endl;
    rep(i, h) cout << "#" << a[i] << "#" << endl;
    rep(i, w + 2) cout << "#";
    cout << endl;

    return 0;
}