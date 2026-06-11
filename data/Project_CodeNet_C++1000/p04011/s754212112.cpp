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
    int n, k, x, y;
    cin >> n >> k >> x >> y;

    if (n <= k) {
        cout << x * n << endl;
    }
    else {
        cout << (k * x) + (n - k) * y << endl;
    }
    
    return 0;
}