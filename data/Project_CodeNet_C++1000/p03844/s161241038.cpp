#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl
#define YORN(f) cout<<((f)?"YES":"NO")<<endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    int a, b;
    char o;
    cin >> a >> o >> b;
    if (o == '+') {
        cout << a + b << endl;
    }
    else {
        cout << a - b << endl;
    }
    return 0;
}