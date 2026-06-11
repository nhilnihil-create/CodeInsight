//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;

#define endl "\n"

const int MOD = 1000000007;


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

    char a, b;
    cin >> a >> b;
    if(a == 'H' && b == 'H')
        cout << "H" << endl;
    else if (a == 'D' && b == 'D')
        cout << "H" << endl;
    else
        cout << "D" << endl;

    return 0;
}
