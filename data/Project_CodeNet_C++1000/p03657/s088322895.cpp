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

    int a, b;
    cin >> a >> b;
    if(a % 3 == 0 )
        cout << "Possible" << endl;
    else if ( b % 3 == 0)
    cout << "Possible" << endl;
    else if((a+b) % 3 == 0)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
	
    return 0;
}
