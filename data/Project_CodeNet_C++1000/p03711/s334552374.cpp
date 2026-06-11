#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl
#define YORN(f) cout<<((f)?"YES":"NO")<<endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;

    int gx = 0, gy = 0;
    if (x == 2) {
        gx = 2;
    }
    if (x == 4 || x == 6 || x == 9 || x == 11) {
        gx = 1;
    }
    if (y == 2) {
        gy = 2;
    }
    if (y == 4 || y == 6 || y == 9 || y == 11) {
        gy = 1;
    }

    yorn(gx == gy);
    
    return 0;
}