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
    string a, b;
    cin >> a >> b;
   // cout << a << " " << b << endl;
    if(a[0] == 'H' && b[0] == 'H')
        cout << "H" << endl;
    else if(a[0] == 'D' && b[0] == 'D')
        cout << "H" << endl;
    else if(a[0] == 'D' && b[0] == 'H')
        cout << "D" << endl;
    else if(a[0] == 'H' && b[0] == 'D')
        cout << "D" << endl;


    return 0;
}
