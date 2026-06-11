#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1999999999
#define MODA 1000000007

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    if(a == 1)
        a += 13;
    if(b == 1)
        b += 13;
    if(a > b)
        cout << "Alice" << endl;
    else if(a < b)
        cout << "Bob" << endl;
    else
       cout << "Draw" << endl;


    return 0;
}
