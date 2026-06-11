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
    YORN((a == 7 && b == c && b == 5) ||
    (b == 7 && a == c && a == 5) ||
    (c == 7 && a == b && a == 5));
    return 0;
}