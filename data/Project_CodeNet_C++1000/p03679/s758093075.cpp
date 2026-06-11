#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl
#define YORN(f) cout<<((f)?"YES":"NO")<<endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    int x, a, b;
    cin >> x >> a >> b;
    if (b - a <= 0) {
        cout << "delicious" << endl;
    }
    else if (b - a <= x) {
        cout << "safe" << endl;
    }
    else {
        cout << "dangerous" << endl;
    }
    return 0;
}