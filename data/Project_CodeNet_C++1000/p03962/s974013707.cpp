#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define yorn(f) cout<<((f)?"Yes":"No")<<endl
#define YORN(f) cout<<((f)?"YES":"NO")<<endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int o = 3;
    if (a == b && b == c) {
        o = 1;
    }
    else if (a == b || b == c || c == a) {
        o = 2;
    }

    cout << o << endl;

    return 0;
}