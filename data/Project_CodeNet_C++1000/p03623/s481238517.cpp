//                     بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
//                   لآ اِلَهَ اِلّا اللّهُ مُحَمَّدٌ رَسُوُل اللّهِ





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
    //ios::sync_with_stdio(0);cin.tie(0);
    int x, a, b;
    cin >> x >> a >> b;
    if(abs(x-b) > abs(x-a)) cout << "A" << endl;
    else cout << "B" << endl;

    return 0;
}
